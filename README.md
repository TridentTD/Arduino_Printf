# Arduino_Printf
Arduino Printf
--------------

สำเนา Print.h และ Print.cpp ไปแทนที่ ของเดิมที่อยู่ในโฟลเดอร์  
C:\Users\..ชื่อuser..\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.18\cores\arduino  
ก็จะสามารถใช้ฟังก์ชั่น printf ได้ใน Serial, lcd, client, Wire ฯลฯ  
  
ตัวอย่างเช่น  
lcd.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());  
Serial.printf("%02d:%02d:%02d", now.hour(), now.minute(), now.second());  
  
เป็นต้น  

