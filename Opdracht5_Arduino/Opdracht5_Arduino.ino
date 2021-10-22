const int ledR = 9;
const int ledG = 10;
const int ledB = 11;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 25; i++) {                         //gaat in 25 stappen steeds meer rood toevoegen
    analogWrite(ledR, i*10);
    for(int i = 0; i < 25; i++) {                       //gaat per hoeveelheid rood in 25 stappen steeds meer groen toevoegen
      analogWrite(ledG, i*10);
      for(int i = 0; i < 25; i++) {                     //gaat per hoeveelheid groen in 25 stappen steeds meer blauw toevoegen
        analogWrite(ledB, i*10);
        delay(10);
      }
    }
  }
}
