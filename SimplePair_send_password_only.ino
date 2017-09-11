#include <ESP8266WiFi.h>
#include <TridentTD_SimplePair.h>

// ค่า SIMPLE_PAIR_KEY ใช้สำหรับเข้ารหัส Simple-Pair ให้ตรงกัน
// Simple-Pair ที่จะจับคู่กัน ต้องตั้งค่านี้ให้ตรงกัน โดยมีความยาวไม่เกิน 16 ตัวอักษร
#define SIMPLE_PAIR_KEY   "HELLO_SIMPLEPAIR"

String PASSWORD      = "9876543210123456";  // พาสเวิร์ดนี้จะถูกส่งไปให้ทาง Simple-Pair 
                                            // โดยมีความยาว 16 ตัวอักษรสูงสุด
void setup() {
  Serial.begin(115200);
  Serial.println();
  
  WiFi.disconnect(true);
  WiFi.softAPdisconnect(true);

  Serial.println("Simple-Pair AP Mode");
  SimplePair.mode(SP_AP);                         // กำหนด SimplePair เป็นโหมด AccessPoint เพื่อเป็นฝั่งส่งข้อมูล
  SimplePair.setSimplePairKey(SIMPLE_PAIR_KEY);   // กำหนด กุญแจ SimplePair Key
  SimplePair.setSimplePairData(PASSWORD);      // ข้อมูล คือ พาสเวิร์ดของ AP นี้จะถูกส่งไปให้ทาง Simple-Pair 
}

void loop() {
  SimplePair.annouce();  // โหมด SP_AP ปล่อยสัญญาณ Simple-Pair เพื่อกระจายข้อมูล AP_PASSWORD ออกไป
}
