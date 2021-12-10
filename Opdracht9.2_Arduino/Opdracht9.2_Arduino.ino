#include <SoftwareSerial.h> 
SoftwareSerial bluetooth(0, 1);
int startsign = 0; 
int LED[] = {4, 3, 2}; 
unsigned long lastTime = 0;
unsigned long lastCheck = 0;
boolean huidigeStaat = false;
int ledStatus = LOW;

void setup() 
{   
 Serial.begin(9600); 
 bluetooth.begin(9600); 
 for(int i : LED) pinMode(i, OUTPUT);
} 
void loop() 
{ 
  if(0 < millis() - lastCheck <= 100) {
    if (bluetooth.available())
      startsign = bluetooth.read();
      if (startsign != 0) Serial.println(startsign);
    if (startsign == 75)
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
    for(int i : LED) digitalWrite(LED[i], LOW);  
    digitalWrite(LED[2], HIGH); 
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
