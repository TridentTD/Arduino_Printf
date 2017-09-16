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
lcd.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());  
Serial.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());  
```

เป็นต้น  

EEPROM สำหรับ บันทึกและอ่านค่า String สำหรับ Arduino เท่านั้น
-----------------------------------------------------
  
ให้สำเนา EEPROM.h นี้ไปแทนที่ ของเดิมที่อยู่ในโฟลเดอร์  
C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\EEPROM\src  

ก็จะสามารถเรียกใช้ คำสั่งบันทึก และอ่านค่า String ลงบน EEPROM ได้ดังนี้  
  
```c
#include <EEPROM.h>

void setup() {
  Serial.begin(115200); Serial.println();

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
