//lab 7 tilstandsmaskin

const int potPin = 2;
const int greenLed = 12;
const int blueLed = 11;
const int redLed = 13;
static int potVal = 0;
enum ledState{BLUE, GREEN, RED};
static unsigned int state;


void setup() {
  // put your setup code here, to run once:
pinMode(greenLed, OUTPUT);
pinMode(blueLed, OUTPUT);
pinMode(redLed, OUTPUT);

//enum state{RED,GREEN,BLUE};


Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(2);
Serial.println(analogRead(2));
if(potVal < 250){
  state = GREEN;
 
}
else if(potVal > 300 && potVal < 750){
  state = BLUE;
}
else if(potVal>850){
  state = RED;
}
colorChange();
}

void colorChange(){
  potVal = analogRead(2);
  switch(state) {
    case BLUE:
    digitalWrite(blueLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    break;
    
    case GREEN:
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW);
    break;
    case RED:
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    digitalWrite(greenLed, LOW);
    break;
    
  }
  
}
