#include <Servo.h>

#include "BYJ48Stepper.h"
Servo myservo;
// 4096 steps per rotation on the BYJ
const unsigned int stepCount = 4096;
const double speed = 15;

Stepper sOptimal1(Stepper::PinGroup::MEGA2560_10_13);
Stepper sOptimal2(Stepper::PinGroup::MEGA2560_6_9);
Stepper sSlow(10, 11, 12, 13);
int pos = 0;


void setup() {
  sOptimal1.setSpeed(speed);
  sSlow.setSpeed(speed);
  Serial.begin(9600);  

  myservo.attach(9);
  myservo.write(pos);
}
int x = 0;
int y = 0;
void loop() {
  
  x = analogRead(6);
  y = analogRead(7);
  if(x/100 != 4 and y/100 != 5){
  motor2(x);
  motor1(x,y);
  Serial.println("x: " + String(x/100) + " y: " + String(y/100));
  //motor();
  }
}

void motor1(int ix, int iy) {
  if(1023/2 > ix){
  sOptimal1.step(10);
  }else{
  sOptimal1.step(-10);
  delay(10);
}
}
void motor2(int ix) {
  myservo.write(ix);
}
