int x;
int y;
int z;
int a;

void setup() {
  // put your setup code here, to run once:
 x = 1;
 y = 1;
 a = 0;
 z = 1;
 while(y<9) {
  pinMode(y, OUTPUT);
  y++;
  }
  y = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while(y<9) {
  digitalWrite(y, LOW);                                               //zet alle leds uit
  y++;
  }
  y = 0;
  digitalWrite(x, HIGH);                                              //zet het led van de laatste loop opnieuw aan
  digitalWrite(x+z, HIGH);                                            //zet het led ernaast aan(afhankelijk van de richting)
 if(x == 0) z = -1;                                                   //verandert de richting als het led laatste of het eerste led aan is geweest in de vorige loop
 if(x == 9) z = 1;
 x = x - z;                                                           //overschrijft het oude led met het nieuwe led
 
 delay(random(200));                                                  //om het wat langzamer te laten gebeuren
}
