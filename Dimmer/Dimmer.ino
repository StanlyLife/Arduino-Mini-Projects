void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
int i = 0;

void loop() {
  if (i < 50){
    analogWrite(13, i);
    delay(50);
    i = i + 1;
    Serial.print(i);
  }else if(i > 49){
    while(i > 1) {
    i = i-1;
    analogWrite(13, i);
    delay(50);
    Serial.print(i);}
}}
