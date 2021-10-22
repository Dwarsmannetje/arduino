#include <Servo.h>
  Servo a;
  int pos = 0;
  int vec = 0;
  const int Pot = A0;

void setup() {
  // put your setup code here, to run once:
  a.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7) && digitalRead(8)) {                    //als bijde knppen ingedrukt zijn wordt de servo langzaam bewogen en blijft hij stilstaan wanneer hij op 120 graden staat
    delay(8);
    if(pos == 120 && vec < 1) vec = 241;
    a.write(ruitenwisser());
  } else 
   if (digitalRead(7) && !digitalRead(8)) {                 //als alleen de eerste knop ingedrukt wordt beweegt de servo langzaam
    delay(8);
    a.write(ruitenwisser());
    if(pos == 120 && vec != 1) vec = 1;
  } else if(digitalRead(8) && !digitalRead(7)) {            //als alleen de tweede knop ingedrukt wordt beweegt de servo snel 
     delay(4);
     a.write(ruitenwisser());
     if(pos == 120 && vec != 1) vec = 1;
  }
}

int ruitenwisser() {                                        //berekening van de richting en de positie waar de servo naartoe moet bewegen
  if(vec == 0) pos++;
  if(vec == 1) pos--;
  if(vec > 1) vec--;
  if(pos <= 0) vec = 0;
  return pos;
}
