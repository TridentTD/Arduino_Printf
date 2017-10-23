```c
/*
 * ESP32 Simple AP Scan  by TridentTD
 * 23 October 2017
 */

#include <WiFi.h>

extern "C" {
#include "esp_wifi.h"
#include "esp_event_loop.h"
}

typedef enum { SCAN_WAIT, SCAN_START, SCAN_DONE } ap_scan_t;

ap_scan_t           scan_status = SCAN_WAIT;
wifi_scan_config_t  scan_config;
uint16_t            scan_count;

void setup() {
  Serial.begin(115200); Serial.println();
  
  ESP_ERROR_CHECK(esp_event_loop_init(scan_handler, NULL) );
  WiFi.mode(WIFI_STA);
  
  scan_config.ssid                  = 0;
  scan_config.bssid                 = 0;
  scan_config.channel               = 0;
  scan_config.show_hidden           = true;
  scan_config.scan_type             = WIFI_SCAN_TYPE_ACTIVE;
  scan_config.scan_time.active.min  = 100;
  scan_config.scan_time.active.max  = 300;
}

void loop() {
  if(scan_status == SCAN_WAIT){
    Serial.println("-------------------------------");
    Serial.println("[AP Scan] scan start");
    if( esp_wifi_scan_start(&scan_config, false) == ESP_OK ){
      scan_status == SCAN_START;
    }
  }
  delay(2000);
}

static esp_err_t scan_handler(void *ctx, system_event_t *event){
  if (event->event_id == SYSTEM_EVENT_SCAN_DONE ) {
    scan_status = SCAN_DONE;
    Serial.println("[AP Scan] AP scan done");
    esp_wifi_scan_get_ap_num(&scan_count);
    if( scan_count ) {
      Serial.printf("[AP Scan] found %d APs\n", scan_count);
      wifi_ap_record_t  scan_record[scan_count];
      esp_wifi_scan_get_ap_records(&scan_count, scan_record);
      for(int i=0; i< scan_count; i++)
        Serial.printf("[AP Scan] %d. %s  (%d dBm)\n", i+1, scan_record[i].ssid, scan_record[i].rssi );
    }else
      Serial.println("[AP Scan] not found");

    Serial.println();
    scan_status = SCAN_WAIT;
  }
}


```
