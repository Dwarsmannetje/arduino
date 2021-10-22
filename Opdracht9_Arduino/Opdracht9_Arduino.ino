/*   
HC05 - Bluetooth AT-Command mode  
modified on 10 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
*/ 
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(0, 1); // RX | TX 
int flag = 0; 
int LED[] = {4, 3, 2}; 
unsigned long lastTime = 0;
unsigned long lastCheck = 0;
boolean huidigeStaat = false;
int ledStatus = LOW;

void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 for(int i : LED) pinMode(i, OUTPUT);
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
  if(0 < millis() - lastCheck <= 100) {
    if (MyBlue.available()) 
      flag = MyBlue.read(); 
      if (flag != 0) Serial.println(flag); 
    if (flag == 75) 
    { 
      lastTime = millis();
      huidigeStaat = true;  
    } 
  }
  if(huidigeStaat) {
    stopLicht();
  } else {
    storing();
  }
}  

void storing() {
  if(millis() - lastTime >= 1000) {
    ledStatus = (ledStatus == LOW) ? HIGH : LOW;
    digitalWrite(LED[1], ledStatus); 
    lastTime = millis(); 
  }
}

void stopLicht() {
  if(millis() - lastTime <= 12000) {
    digitalWrite(LED[2], HIGH); 
    digitalWrite(LED[1], LOW);  
  }
  if(12000 < millis() - lastTime && millis() - lastTime <= 18000) {
    digitalWrite(LED[2], LOW); 
    digitalWrite(LED[1], HIGH); 
  }
  if(18000 < millis() - lastTime && millis() - lastTime <= 30000) {
    digitalWrite(LED[1], LOW); 
    digitalWrite(LED[0], HIGH); 
  }
  if(millis() - lastTime >= 30000) { 
    digitalWrite(LED[0 ], LOW); 
    huidigeStaat = false;
    lastTime = millis();
  }
}
