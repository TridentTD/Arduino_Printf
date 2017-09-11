#include <ESP8266WiFi.h>
#include <TridentTD_SimplePair.h>

// ค่า SIMPLE_PAIR_KEY ใช้สำหรับเข้ารหัส Simple-Pair ให้ตรงกัน
// Simple-Pair ที่จะจับคู่กัน ต้องตั้งค่านี้ให้ตรงกัน โดยมีความยาวไม่เกิน 16 ตัวอักษร
#define SIMPLE_PAIR_KEY   "HELLO_SIMPLEPAIR"

String SSID = "---YOUR ROUTER SSID---";  // ใส่ชื่อ SSID ที่ต้องการเชื่อมต่อ
String PASSWORD;                         // PASSWORD ไม่ต้องกำหนด จะทำการรับจาก SimplePair แทน

void setup() {
  Serial.begin(115200);
  Serial.println();

  Serial.println("Simple-Pair STA Mode");
  
  SimplePair.mode(SP_STA);                               // กำหนด SimplePair เป็นโหมด STATION
  SimplePair.setSimplePairKey(SIMPLE_PAIR_KEY);          // กำหนด กุญแจ SimplePair Key
  SimplePair.onReceivedData([](){                        // เมื่อมีการรับค่าทาง SimplePair เข้ามา
      PASSWORD    = SimplePair.getSimplePairData(); 
      Serial.println("Recv. PASSWORD : " + PASSWORD);
    });

  SimplePair.scanSP();  // โหมด STATION ทำการเริ่มแสกนหา Simple-Pair ที่ annouce ออกมา

  if( PASSWORD != "") {
    //เชื่อมต่อ WiFi
    WiFi.begin(SSID.c_str(), PASSWORD.c_str());
    while (WiFi.status() != WL_CONNECTED);
    Serial.println("WiFi connected to ssid " + SSID);
    Serial.print("IP Address is "); Serial.println(WiFi.localIP());
  }
}

void loop() {
}
