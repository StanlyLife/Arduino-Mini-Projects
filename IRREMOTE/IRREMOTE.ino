#include <LiquidCrystal.h>

#include <IRremote.h>

int bled = 11;
int gled = 12;
int rled = 13;
int RECV_PIN = 8;


LiquidCrystal lcd(9,2,4,5,6,7);

int ir = 0;
String lb;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(RECV_PIN, INPUT);  
  pinMode(gled, OUTPUT); 
  pinMode(bled, OUTPUT);
  pinMode(rled, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600);

  lcd.begin(16,2);
}
void loop() {
  lcd.print("Test");
  //digitalWrite(gled,LOW);
  //digitalWrite(bled,HIGH);
  //digitalWrite(rled,LOW);
  //BLAA

  //ROD
  //digitalWrite(gled,LOW);
  //digitalWrite(bled,LOW);
  //digitalWrite(rled,HIGH);

  //GRONN
  //digitalWrite(gled,HIGH);
  //digitalWrite(bled,LOW);
  //digitalWrite(rled,LOW);
   
   //Serial.println(fakulitet(30));
   if (irrecv.decode(&results)) {
   
           lb = translateIR();
           if(lb != 0) {
           Serial.println(fakulitet(lb.toInt()));
             if(lb == "1"){
              //GRONNl
              digitalWrite(gled,HIGH);
              digitalWrite(bled,LOW);
              digitalWrite(rled,LOW);
           }else if(lb == "2"){
              digitalWrite(gled,LOW);
              digitalWrite(bled,LOW);
              digitalWrite(rled,HIGH);
           }else if(lb == "3"){
              digitalWrite(gled,LOW);
              digitalWrite(bled,HIGH);
              digitalWrite(rled,LOW);
           }else if(lb == "4"){
              digitalWrite(gled,LOW);
              digitalWrite(bled,LOW);
              digitalWrite(rled,LOW);
           }else if(lb == "5"){
              digitalWrite(gled,LOW);
              digitalWrite(bled,LOW);
              digitalWrite(rled,LOW);
           }else if(lb == "6"){
              digitalWrite(gled,LOW);
              digitalWrite(bled,LOW);
              digitalWrite(rled,LOW);
           }
           
           
           
           }
    
           
   irrecv.resume(); // Receive the next value   
   }  
    
 }

void screenPrint(int inp){
  lcd.write(inp);
}

 String translateIR() // takes action based on IR code received describing Car MP3 IR codes 
{
  switch(results.value){
  case 0xFFA25D:  
    return "CH-";
    break;
  case 0xFF629D:  
    return "CH";
    break;
  case 0xFFE21D:  
    return "CH+";
    break;
  case 0xFF22DD:  
    return "blue LED off";
    break;
  case 0xFF02FD:  
    return "blue LED on";
    break;
  case 0xFFC23D:  
    return "PLAY/PAUSE";
    break;
  case 0xFFE01F:  
    return "VOL-";
    break;
  case 0xFFA857:  
    return "VOL+";
    break;
  case 0xFF906F:  
   return "EQ";
    break;
  case 0xFF6897:  
    return "0";
    break;
  case 0xFF9867:  
    return "100+";
    break;
  case 0xFFB04F:  
    return "200+";
    break;
  case 0xFF30CF:  
    return "1";
    break;

  case 0xFF18E7:  
    return "2";
    break;

  case 0xFF7A85:  
    return "3";
    break;

  case 0xFF10EF:  
    return "4";
    break;

  case 0xFF38C7:  
    return "5"; 
    break;

  case 0xFF5AA5:  
    return "6";
    break;

  case 0xFF42BD:  
    return "7";
    break;

  case 0xFF4AB5:  
    return "8";
    break;

  case 0xFF52AD:  
    return "9";
    break;

  case 0xFFFFFF:
    return "WHAAAT";
    break;


  default: 
    Serial.print(" unknown button   ");
  }
  delay(400);
} 
                  
void unknownRemoter(){                       //this function is from an old remoter see video.
long RED_LED_OFF = 0xFF40BF;
long RED_LED_ON =  0xFF906F;
long LAST_BUTTON = 0xFFD02F;

if (results.value == RED_LED_OFF){
      Serial.println ("Red led off");
      digitalWrite(12,LOW);
      }
     else if (results.value == RED_LED_ON )
      {
       Serial.println ("Red led on");
      digitalWrite(12,HIGH);
      }
     else if (results.value == LAST_BUTTON )
      {
       Serial.println ("CAMERA IMAGE button");
      }else{
         Serial.print(" still an unknown button   ");
         Serial.println(results.value, HEX);
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
