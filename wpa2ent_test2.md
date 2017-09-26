```c
// ทดสอบแบบ ต้องมี cer & key

#include <ESP8266WiFi.h>
#include "cer.h"

extern "C" {
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}

// SSID to connect to
static const char* ssid     = "ssidname";
static const char* username = "user";
static const char* password = "password";


void setup() {
  Serial.begin(115200); Serial.println();

  WiFi.mode(WIFI_STA);
  wifi_station_set_username((uint8_t*)username, sizeof(username));
  if( wifi_station_set_cert_key(testuser_cert_pem, testuser_cert_pem_len, testuser_key_pem, testuser_key_pem_len, NULL, 0) == 0 ) {
        Serial.println("set cert key");
  }
  WiFi.begin(ssid, password);
  
  // Wait for connection AND IP address from DHCP
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  // Now we are connected
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  wifi_station_clear_cert_key();
  wifi_station_clear_username();
}

void loop() {
  // put your main code here, to run repeatedly:

}

```
