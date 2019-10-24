void setup() {
  pinMode(3,OUTPUT); //A2
  pinMode(4,OUTPUT); //B2
  
  pinMode(6,OUTPUT); //A1
  pinMode(7,OUTPUT); //B1
  
  pinMode(9,OUTPUT); //A0
  pinMode(10,OUTPUT); //B0
  Serial.begin(9600);
}

String bits = "HLLLHL  ";
char bitArr[5];
int num = 0;


void loop() {


digitalWrite(3,HIGH); //A0
digitalWrite(6,HIGH); //A1
digitalWrite(9,HIGH); //A2


digitalWrite(4,LOW); //B0
digitalWrite(7,LOW); //B1
digitalWrite(10,LOW); //B2
}
