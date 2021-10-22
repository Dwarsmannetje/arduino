
const int led = 11;
const int button = 4;
int z;
int a;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
 a = 0;
 z = 1;
}
 
void loop() {
  // put your main code here, to run repeatedly:
  //a wordt gereset wanneer de knop los wordt gelaten
  if(digitalRead(button) == LOW) {
    a = 0;
  }
  //als a 0 is wanneer de knop ingedrukt wordt wordt de waarde z omgedraait van positief naar negatief of andersom. hierna wordt a naar 1 geset. hierdoor wordt de waarde z alleen omgedraait wanneer de knop ingedrukt wordt en wordt dit niet herhaald wanneer de knop vastgehouden wordt
  if(digitalRead(button) == HIGH) {
    if(a == 0) {
      z = -z;
    }
    a = 1;
  }
 //hier wordt afhankelijk of de waarde z positief of negatief is de lamp aan- of uitgezet.
 if(z == 1) digitalWrite(led, LOW);
 if(z == -1) digitalWrite(led, HIGH);
 delay(50);
}
