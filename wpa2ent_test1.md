```c
// ทดสอบแบบที่ 1

#include <ESP8266WiFi.h>

extern "C" {
  #include "user_interface.h"
  #include "wpa2_enterprise.h"
}
// SSID to connect to
static const char* ssid     = "ssidname";
static const char* username = "identity";
static const char* password = "password";


void setup() {
  Serial.begin(115200); Serial.println();

  WiFi.mode(WIFI_STA);

  struct station_config wifi_config;
  memset(&wifi_config, 0, sizeof(wifi_config));
  strcpy((char*)wifi_config.ssid, ssid);
  wifi_station_set_config(&wifi_config);


  wifi_station_clear_cert_key();
  wifi_station_clear_enterprise_ca_cert();
  wifi_station_set_wpa2_enterprise_auth(1);
  wifi_station_set_enterprise_username((uint8*)username, strlen(username));
  wifi_station_set_enterprise_password((uint8*)password, strlen(password));
  wifi_station_connect();

  // Wait for connection AND IP address from DHCP
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }

  // Now we are connected
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
```
