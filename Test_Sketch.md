ตัวอย่าง


```c
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid     = "........";
const char* password = "........";

ESP8266WebServer server(80);

void handleGPIO(){
  int pin;
  int status;

  for(int i =0; i < server.args(); i++){
    if( server.argName(i) == "pin" ) {
      pin = server.arg(i).toInt();
    }
    else if ( server.argName(i) == "status" ) {
      status = server.arg(i).toInt();
    }
  }

  if( pin == 2 || pin == 5 ) {
    digitalWrite( pin, status);
    Serial.printf("GPIO %d : %d\n", pin, status);
    server.send(200,"text/html", String("GPIO : ") + String(pin) + String("<br>\nSTATUS : ") + String(status));
  } else{
    server.send(200,"text/html", "----");
  }
}

void setup(){
  Serial.begin(115200); Serial.println();
  WiFi.begin(ssid, password);
  while(!uint32_t(WiFi.localIP())) delay(500);
  Serial.println(WiFi.localIP());

  pinMode( 2, OUTPUT );
  pinMode( 5, OUTPUT );

  Serial.println("Webserver Start!");
  server.on("/gpio", handleGPIO );
  server.begin();
}

void loop() {
  server.handleClient();
}

```
