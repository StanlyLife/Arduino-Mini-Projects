void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);

  //krets
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  //knapper
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  
}

int b1 = 0;
int b2 = 0;
int b3 = 0;
int b4 = 0;

String b1s = "L";
String b2s = "L";
String b3s = "L";
String b4s = "L";
String b5s = "L";
String b6s = "L";

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("TEST");

  b1 = digitalRead(2);
  b2 = digitalRead(3);
  b3 = digitalRead(4);
  b4 = digitalRead(5);

  //BUTTON 111111111
  if(b1 != 0) {
  Serial.println("");
  flip(b1s,1);
  Serial.println("");
  Serial.println("B1 pressed");
  delay(300);
  Serial.println("b1s: " + b1s);
}
  //BUTTON 22222222
  if(b2 != 0) {
  Serial.println("");
  flip(b2s,2);
  Serial.println("");
  Serial.println("B2 pressed");
  delay(300);
  Serial.println("b2s: " + b2s);
}
  //BUTTON 33333333
  if(b3 != 0) {
  Serial.println("");
  flip(b3s,3);
  Serial.println("");
  Serial.println("B3 pressed");
  Serial.println("b3s: " + b3s);
  delay(500);
}
  //BUTTON 44444444
  if(b4 != 0) {
  Serial.println("");
  flip(b4s,4);
  Serial.println("");
  Serial.println("B4 pressed");
  delay(300);
  Serial.println("b4s: " + b4s);
}



state();
}//end of loop

void flip(String state, int button){
    switch (button) {
          case 1://for button 1
            if(state == "H"){
              b1s = "L";
            }else{
              b1s = "H";
            }break;
          case 2: //for button 2
            if(state == "H"){
              b2s = "L";
            }else{
              b2s = "H";
            }
      break;
          case 3: //for button 3
            if(state == "H"){
              b3s = "L";
            }else{
              b3s = "H";
            }
      break;
          case 4: //for button 4
            if(state == "H"){
              b4s = "L";
            }else{
              b4s = "H";
            }
      break;
          default:
      // if nothing else matches, do the default
      // default is optional
      Serial.println("ERROR IN CASE SWITCH");
      break;
    }
      Serial.println("BITS: " + b1s + b2s + b3s +b4s);
    }

void state(){
  //111111111
  if(b1s == "H"){
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
  }else{
    digitalWrite(10,LOW);
    digitalWrite(6,LOW);
  }
  //22222222
    if(b2s == "H"){
    digitalWrite(7,HIGH);
    digitalWrite(11,HIGH);
  }else{
    digitalWrite(7,LOW);
    digitalWrite(11,LOW);
  }
  //33333333
    if(b3s == "H"){
    digitalWrite(8,HIGH);
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(8,LOW);
    digitalWrite(12,LOW);
  }
  //4444444
    if(b4s == "H"){
    digitalWrite(9,HIGH);
    digitalWrite(13,HIGH);
  }
  else{
    digitalWrite(9,LOW);
    digitalWrite(13,LOW);
  }
    //55555
    if(b5s == "H"){
    //digitalWrite(9,HIGH); ///
    //digitalWrite(13,HIGH); ///
  }
  else{
    //digitalWrite(9,LOW); ///
    //digitalWrite(13,LOW); ///
  }
      //6666666
    if(b6s == "H"){
    //digitalWrite(9,HIGH); ///
    //digitalWrite(13,HIGH); ///
  }
  else{
    //digitalWrite(9,LOW); ///
    //digitalWrite(13,LOW); ///
  }
}
