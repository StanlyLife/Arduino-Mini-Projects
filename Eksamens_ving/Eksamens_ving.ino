void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

boolean ja = true;

enum test {
RED,GREEN
};

test farge = RED;

void loop() {

if (ja){
  Serial.println("true");
    ja = !ja;
}else{
  Serial.println("false");
  ja = !ja;
}

Serial.println(ja);
 switch(farge){
  case RED:
  Serial.println("RED");
  break;

  case GREEN:
  Serial.println("GREEN");
  break;
 }

}
