# Arduino_Printf
Arduino Printf
--------------

สำเนา Print.h และ Print.cpp ไปแทนที่ ของเดิมที่อยู่ในโฟลเดอร์  
C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino  
  
หรือ หากมีโฟลเดอร์นี้อยู่ในไปวางไว้ที่นี่ด้วย  
C:\Users\..ชื่อuser..\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.18\cores\arduino  

ก็จะสามารถใช้ฟังก์ชั่น printf ได้ใน Serial, lcd, client, Wire ฯลฯ  
  
ตัวอย่างเช่น  

```c
lcd.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());     // แสดงเวลาปัจจุบันออกจอ lcd เช่นได้ 12:45:34
Serial.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());  // แสดงเวลาปัจจุบันออก Serial monitor เช่นได้ 12:45:34
```

เป็นต้น  

EEPROM สำหรับ บันทึกและอ่านค่า String (Arduino เท่านั้น)
-----------------------------------------------------
  
ให้สำเนา EEPROM.h นี้ไปแทนที่ ของเดิมที่อยู่ในโฟลเดอร์  
C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src  

ก็จะสามารถเรียกใช้ คำสั่งบันทึก และอ่านค่า String ลงบน EEPROM ได้ดังนี้  
  
```c
#include <EEPROM.h>

void setup() {
  Serial.begin(115200);
  
  int    addr     = 0x10;              // Address บน EEPROM ที่ต้องการบันทึก/อ่านค่า
  String myString = "Hello EEPROM123"; // String ที่ต้องการบันทึก
  int    len      = myString.length(); // ความยาว String

  // บันทึก String ลงบน EEPROM
  EEPROM.writeString( addr, myString);

  // อ่านค่า String จาก EEPROM
  String eepromString = EEPROM.readString( addr , len); 
  Serial.println( eepromString );
}

void loop() {
}
```

String split function for ESP8266
---------------------
ให้สำเนา WString.h และ WString.cpp นี้ไปแทนที่ ของเดิมที่อยู่ในโฟลเดอร์  
C:\Users\[user_name]\AppData\Local\Arduino15\packages\esp8266\hardware\esp8266\[esp_version]\cores\esp8266

ก็จะสามารถทำการตัดแบ่งคำ ได้ง่ายๆ ตามตัวอย่าง
```c
void setup() {
  Serial.begin(115200); Serial.println();
  
  String myString = "Helo My name, is TridentTD. Hey(Hana";
  
  Serial.println("-----------------------------");
  Serial.println(myString);
  Serial.println("-----------------------------");

  int     MAX = 10;           // ขนาดสูงสุดที่จะตัดแบ่งคำ
  String  str_split[MAX];     // ตัวแปร String ที่จะมาเก็บคำที่ตัดแบ่งแล้ว
  String  delimitor = " ,.("; // หากพบ space หรือ , หรือ . หรือ ( จะใช้เป็นตัวตัดแบ่งคำ

  // myString ทำการตัดแบ่งคำ แล้วเก็บใน str_split[]
  int count = myString.split( str_split, MAX, delimitor ); 
  for(int i =0; i < count ; i++){
    Serial.println(str_split[i]); // แสดงค่าที่ตัดแบ่งคำ
  }
}

void loop() {
  delay(1);
}

// [OUTPUT]
//
// -----------------------------
// Helo My name, is TridentTD. Hey(Hana
// -----------------------------
// Helo
// My
// name
// is
// TridentTD
// Hey
// Hana
```
