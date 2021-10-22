const int Pot = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(map(analogRead(Pot), 0, 1023, 0, 500));      //geeft de gemeten temperatuur in graden celsius weer
}
  
