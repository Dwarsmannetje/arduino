const int led1 = 7;
const int led2 = 8;
const int led3 = 9;
const int led4 = 10;
const int led5 = 11;
const int led6 = 12;
const int led7 = 13;
int randomLed[] = {200, 400, 500, 600, 700, 800, 950};

const int Pot = A0;
int y1;
int y2;
int y3;
int y4;
int y5;
int y6;
int y7;
int a;
int b;
int c;
int d;
int e;
int f;
int counter;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  y1 = 7;
  while(y1<14) {
  pinMode(y1, OUTPUT);
  y1++; 
  }
  a = random(7);
  b = random(6);
  c = random(5);
  d = random(4);
  e = random(3);
  f = random(2);
  y7 = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  y1 = a;
  y2 = b;
  y3 = c;
  y4 = d;
  y5 = e;
  y6 = f;
  if( counter > 1000) {
  a = random(7);
  b = random(6);
  c = random(5);
  d = random(4);
  e = random(3);
  f = random(2);
  counter = 0;
  }
  counter++;
  
  randomLed[0] = 200;
  randomLed[1] = 400;
  randomLed[2] = 500;
  randomLed[3] = 600;
  randomLed[4] = 700;
  randomLed[5] = 800;
  randomLed[6] = 950;
  digitalWrite(led1, map(analogRead(Pot), 0, randomLed[y1], 0, 1));
  while(y1 < 6) {
    randomLed[y1] = randomLed[y1+1];
    y1++;
  }
  digitalWrite(led2, map(analogRead(Pot), 0, randomLed[y2], 0, 1));
  while(y2 < 5) {
    randomLed[y2] = randomLed[y2+1];
    y2++;
  }
  digitalWrite(led3, map(analogRead(Pot), 0, randomLed[y3], 0, 1));
  while(y3 < 4) {
    randomLed[y3] = randomLed[y3+1];
    y3++;
  }
  digitalWrite(led4, map(analogRead(Pot), 0, randomLed[y4], 0, 1));
  while(y4 < 3) {
    randomLed[y4] = randomLed[y4+1];
    y4++;
  }
  digitalWrite(led5, map(analogRead(Pot), 0, randomLed[y5], 0, 1));
  while(y5 < 2) {
    randomLed[y5] = randomLed[y5+1];
    y5++;
  }
  digitalWrite(led6, map(analogRead(Pot), 0, randomLed[y6], 0, 1));
  while(y6 < 1) {
    randomLed[y6] = randomLed[y6+1];
    y6++;
  }
  digitalWrite(led7, map(analogRead(Pot), 0, randomLed[0], 0, 1));
  
}
