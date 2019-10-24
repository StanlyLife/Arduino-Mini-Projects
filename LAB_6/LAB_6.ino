#include <dht.h>
#define DHT11_PIN A7
const int button1 = 2;
const int button2 = 3;
const int led = 13;
const int maaler = 7;

  typedef struct weather {
  int temp;
  int humidity;
  };

void setup() {


  
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pinMode(maaler,INPUT);

  attachInterrupt(digitalPinToInterrupt(button1), blink, HIGH);
  attachInterrupt(digitalPinToInterrupt(button2), dim, HIGH);
  Serial.begin(9600);
}

int b1 = 0;
int b2 = 0;
dht DHT;

weather maaling[11];

volatile byte state = LOW;
unsigned long buttonPushedMillis;
unsigned long buttonPushedMillis2;
unsigned long currentMillis;

int i = 1;
int brightness = 0;



void loop() {
  int chk = DHT.read11(DHT11_PIN);
  currentMillis = millis();

  analogWrite(led, brightness);

  
  if(DHT.temperature != 0 && DHT.temperature != -999 && i <= 11){
  maaling[i].temp = DHT.temperature;
  maaling[i].humidity = DHT.humidity;
  Serial.println(i);
  Serial.println(maaling[i].temp);
  i++;
  }
}


void printArr() {
  int totTemp = 0;
  int totHum = 0;
  for(int x = 1; x != sizeof(maaling)/4; x++){
    totTemp = totTemp + maaling[x].temp;
    totHum += maaling[x].humidity;
      
      if(x == (sizeof(maaling)/4 -1)){
        Serial.println("Average temperature = " + String(totTemp/x));
        Serial.println("Average Humidity = " + String(totHum/x));
        //Serial.println(x);
        Serial.println();
      }//end of if
  }//end of for loop
}//END OF FUNC
void blink() {
    if(buttonPushedMillis + 200 < currentMillis){
      brightness += 10;
      //Serial.println(String(buttonPushedMillis) + " " + String(currentMillis) );
      buttonPushedMillis = currentMillis;
      printArr();

      Serial.println("brightness = " + String(brightness));
  }
}
void dim() {
  if(buttonPushedMillis2 + 200 < currentMillis){
      brightness -= 10;
      buttonPushedMillis2 = currentMillis;
      Serial.println("Brightness: " + String(brightness));
  }
}
