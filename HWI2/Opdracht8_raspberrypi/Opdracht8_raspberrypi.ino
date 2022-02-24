int LED[] = {6, 7};
int status[] = {LOW, HIGH};
int signalState = LOW;
int signal2State = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(9, INPUT);
  for(int i : LED) pinMode(i, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(6, digitalRead(10));
  //digitalWrite(7, !digitalRead(10));
  //digitalWrite(11, digitalRead(13));
  if(signal2State) signal2State = digitalRead(9);
  if(digitalRead(9) != signal2State) {
    signalState = (signalState == LOW) ? HIGH : LOW;
    digitalWrite(8, signalState);
    signal2State = HIGH;
  }
}
