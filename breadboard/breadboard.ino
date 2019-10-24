const int buttonPin = 2;
int buttonState = 0;
int potState = 999;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);

  Serial.print(potState);
}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState = digitalRead(13);
  potState = analogRead(2);
  if(potState > 300) {
    tone(12, potState);
  }else{
    noTone(12);
  }
  if(buttonState == HIGH) {
    Serial.print(potState);
    Serial.print("\n");
  }
}
