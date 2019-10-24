String readString;
#include <Servo.h> 
Servo myservo;  // create servo object to control a servo 

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  Serial.println("servo-test"); // so I can keep track of what is loaded
}

void loop() {

  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }

  if (readString.length() >0) {
    Serial.println(readString);  //so you can see the captured String 
    int n = readString.toInt();  //convert readString into a number
//    Serial.println(n); //so you can see the integer
    myservo.write(n);
    fakulitet(n);
    readString="";
  } 
}


int a = 0;

int fakulitet(int num) {
  if(num > 0){
    int x = num;
    unsigned long y = num;
    while(x>1){
      
      y = y*(x-1);
      x= x-1;
    }
    Serial.println(y);
    }else {
      return 1;
    }
  }
