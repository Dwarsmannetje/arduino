#include <IRremote.h>

const int irPin = 8;
const int ledPins[] = {7, 6, 5, 4};
int knipperTimes[] = {500, 500, 0, 0};
int lastTime = 0;
int currentLed = 0;
int knippert = 2;
int gekoppeld = 0;
long Buttons[] = {16738455, 16724175, 16718055, 16743045, 16716015, 16726215, 16734885, 16734885, 16730805, 16732845};
int num_0 = 0xFF6897;
#define  NUM1 0xFF30CF

unsigned long lastTimes[] = {0, 0, 0, 0};

int ledStatus[] = {LOW, LOW, LOW, LOW};
int led = LOW;
IRrecv irrecv(irPin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  for(int i : ledPins) {
    pinMode(i, OUTPUT);
  }
  pinMode(3, OUTPUT);
}

void loop(){
  if(millis() - lastTime >= 100) {                                    //vertraging voor lezen van de IRremote
    lastTime = millis();                                              
    if(irrecv.decode(&results)) {                                     //lezen van de IRremote
      irrecv.resume();                                                
      if(gekoppeld < 10) {                                            //controle of de afstandsbediening gekoppeld is
        Serial.println(results.value);                                
        if(results.value <=20000000 && results.value >= 10000000) {   //controle of de gelezen waarde ruis is of de afstandbediening
          Buttons[gekoppeld] = results.value;                         //koppeld de ingedrukte knop
          Serial.print("knop ");
          Serial.print(gekoppeld);
          Serial.print(" gekoppeld met code: ");
          Serial.println(results.value);
          led = (led == LOW) ? HIGH : LOW;
          digitalWrite(3, led);                                       //zet de led aan of uit wanneer er een knop gekoppeld is
          gekoppeld++;                                                //noteerd dat er een knop gekoppeld is
        }
      } else if(currentLed == 0) {                                    //controleerd of er nog geen led geselecteerd is
        for(int i = 1; i < 5; i++) {                                  //gaat iedere optie langs
          if((results.value) == (Buttons[i])) {                       //controleerd of de ingedrukte knop overeenkomt met de knop voor het led
            currentLed = i;                                           //slaat het geselecteerde led op
          }
        }
      } else {
        digitalWrite(3, HIGH);                                        //zet led aan om aan te geven dat een led is geselecteerd
        for(int i = 0; i < 10; i++) {                                 
          if((results.value) == (Buttons[i])) {                       //controleerd voor iedere snelheid of die geselecteerd is
            a(i);                                                     //past de snelheid van het geselecteere led aan
          }
        }
      }
    }
  }
  for(int i : ledPins) {
    i = i-4;
    if(millis() - lastTimes[i] >= knipperTimes[i] && knipperTimes[i] != 0) {
      lastTimes[i] = millis();
      ledStatus[i] = (ledStatus[i] == LOW) ? HIGH : LOW;
      digitalWrite(ledPins[i], ledStatus[i]);                         //verandert de led van aan naar uit en andersom op de geselecteerde snelheid
    } else if(knipperTimes[i] == 0) {
      digitalWrite(ledPins[i], LOW);                                  //als de geselecteerde snelheid voor het led 0 is dan wordt het led uit gezet
    }
  }
}

void a(int mode) {
  if(mode == 0) {
    knippert = 0;
    for(int i : knipperTimes) {
      if(i != 0) {
        knippert++;                                                   //telt hoeveel leds er aan het knipperen zijn wanneer er geprobeerd wordt om een led uit te zetten
      }
    }
  }
  if(mode != 0 || knippert > 2) {
    knipperTimes[currentLed-1] = mode * 100;                          //verandert de snelheid van het geselecteerde led afhankelijk van de snelheidskeuze
    currentLed = 0;                                                   //reset de selectie
    digitalWrite(3, LOW);                                             //zet het led dat aangaf dat er een led geselecteerd is uit
  }
}
