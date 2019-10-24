const int p1 = 13;
const int p2 = 3;
const int p3 = 4;

const int b1 = 5;
const int b2 = 6;
const int b3 = 7;

int b1State = 0;
int b2State = 0;
int b3State = 0;

int myKeys[5]={0,0,0,0,0};
int myPass[5]={1,2,3,3,2};
int myNumber = 5;

const int gLys = 10;
const int bLys = 11;
const int rLys = 12;

const int buzzer = 4;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(buzzer,OUTPUT);

  //buttons
  pinMode(b1,INPUT);
  pinMode(b2,INPUT);
  pinMode(b3,INPUT);

  pinMode(b3,OUTPUT);
  pinMode(rLys,OUTPUT);
  pinMode(bLys,OUTPUT);
  pinMode(gLys,OUTPUT);
  //start
}

void loop() {
  // put your main code here, to run repeatedly:
  
  b1State = digitalRead(b1);
  b2State = digitalRead(b2);
  b3State = digitalRead(b3);
  
  if(b1State == 1){
     digitalWrite(bLys,HIGH);
    tone(buzzer,5);
    delay(100);
    noTone(buzzer);
      digitalWrite(bLys,LOW);
    
    appender(1);
  }else if(b2State == 1){
    digitalWrite(bLys,HIGH);
    
    tone(buzzer,10);
    delay(100);
    noTone(buzzer);
    digitalWrite(bLys,LOW);
    
    appender(2);
    
  }else if(b3State != 0){
    digitalWrite(bLys,HIGH);
    
    tone(buzzer,15);
    delay(100);
    noTone(buzzer);
    digitalWrite(bLys,LOW);
    
    appender(3);
  }
  
}
void block(){
  
      tone(buzzer,30);
      digitalWrite(rLys,HIGH);
  delay(500);
  noTone(buzzer);
      tone(buzzer,10);
      digitalWrite(rLys,HIGH);
  delay(500);
  noTone(buzzer);
      tone(buzzer,50);
      digitalWrite(rLys,LOW);
  delay(500);
  noTone(buzzer);
      tone(buzzer,20);
      digitalWrite(rLys,HIGH);
  delay(500);
  noTone(buzzer);
  digitalWrite(rLys,LOW);
}

void unlock(){
  Serial.println("UNLOCKED");
    tone(buzzer,1400);
    digitalWrite(gLys,HIGH);
  delay(500);
  noTone(buzzer);
    tone(buzzer,1300);
  delay(500);
  noTone(buzzer);
    tone(buzzer,1500);
  delay(500);
  noTone(buzzer);
  tone(buzzer,1200);
  delay(500);
  noTone(buzzer);
    digitalWrite(gLys,LOW);

  myKeys[0]=0;
  myKeys[1]=0;
  myKeys[2]=0;
  myKeys[3]=0;
  myKeys[4]=0;
  
}

bool testCode() {
  if(myKeys[0] == myPass[0] and
  myKeys[1] == myPass[1] and
  myKeys[2] == myPass[2] and
  myKeys[3] == myPass[3] and
  myKeys[4] == myPass[4]
    ){
      Serial.println("RETT PASSORD!");
      return true;
    }else{
      block();
      Serial.println("FEIL PASSORD!");
      return false;
    }
}


void appender(int num) {
  if (myNumber > 3) {
     bool testkode = testCode();
    if(testkode){
      unlock();
    }else{
  myNumber = 0;
  myKeys[0]=0;
  myKeys[1]=0;
  myKeys[2]=0;
  myKeys[3]=0;
  myKeys[4]=0;
  myKeys[myNumber] = num;
  Serial.println(myKeys[0]);
  Serial.println(myKeys[1]);
  Serial.println(myKeys[2]);
  Serial.println(myKeys[3]);
  Serial.println(myKeys[4]);
  Serial.println(" ");
  Serial.println(myNumber);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  
    delay(220);
    }
  }else{
  myNumber += 1;
  myKeys[myNumber] = num;
  Serial.println(myKeys[0]);
  Serial.println(myKeys[1]);
  Serial.println(myKeys[2]);
  Serial.println(myKeys[3]);
  Serial.println(myKeys[4]);
  Serial.println(" ");
  Serial.println(myNumber);
  Serial.println(" ");
  Serial.println(" ");
  Serial.println(" ");
  delay(220);
  }
}
