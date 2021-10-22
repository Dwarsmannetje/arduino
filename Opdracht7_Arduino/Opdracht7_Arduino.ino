#include <Servo.h>
  Servo a;

float cm = 0;

float readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  a.attach(11);
}

void loop() {
  cm = readUltrasonicDistance(7, 8)/58;               //leest de afstand van de ultrasoonsensor in centimeters(ongeveer)
  if (cm <= 10) {                                     //als de afstand minder of gelijk is dan 10 cm staat de servo de ene kant op
    a.write(0);}                                      
  if (cm == 4) {                                      //als de afstand gelijk is aan 4 cm dan staat de servo de andere kant op
     a.write(180);
  } else if (4 <= cm && 10 >= cm) {                   //als de servo tussen of gelijk is aan 4 en 10 cm dan beweegt de servo afhankelijk van hoeveel afstand er gemeten wordt
    a.write(map(cm-4, 0,6, 180,0));
  } else {                                            //anders staat de servo in ruststand
      a.write(0);}                      
  delay(100);
}
