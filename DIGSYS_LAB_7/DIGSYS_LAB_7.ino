void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  
  valueTown(); //Print to monitor
  //pulse(); //CLK PULSE
  
  delay(250);

}

int HL = 0;
void pulse(){
  if(HL % 2 == 0) {
  digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
  HL++;
}

int q1 = 0;
int q2 = 0;
int q3 = 0;

String a = "";
String b = "";
String c = "";

int sum = 0;
String binSum = "000";

void check() {
  q1 = digitalRead(7);
  q2 = digitalRead(8);
  q3 = digitalRead(9);

  a = String(q1);
  b = String(q2);
  c = String(q3);
}

void valueTown() {
  check(); //Read inputs
  binSum = String(c+b+a);
  Serial.println("binsum: " + binSum);

  if(binSum == "000"){
    Serial.println("0");
  }else if(binSum == "001") {
    Serial.println("1");
  }
  else if(binSum == "010") {
    Serial.println("2");
  }
  else if(binSum == "011") {
    Serial.println("3");
  }
  else if(binSum == "100") {

    Serial.println("4");
  }
  else if(binSum == "101") {
    Serial.println("5");
  }
  else if(binSum == "110") { 
    Serial.println("6");
  }
  else if(binSum == "111") {
    Serial.println("7");
  }else{
    Serial.println("OUT OF SCOPE!");
    Serial.println(binSum);
  }
  
}
