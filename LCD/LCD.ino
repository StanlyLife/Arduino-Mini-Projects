
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6,7);

byte slash[8] = {
B00001,
B00010,
B00100,
B01000,
B10000,
B00000,
B00000,
B00000,
};

String WaitForInput(String Question) {
  Serial.println(Question);
  
  while(!Serial.available()) {
    // wait for input
  }
  
  return Serial.readStringUntil(10);
}

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  //Keyboard.begin();
  //lcd.createChar(7,slash);


  //String ReceivedInput;

  //ReceivedInput = WaitForInput("Please enter your first name.");
  //Serial.print("Your first name is: ");
  //Serial.println(ReceivedInput);

  //ReceivedInput = WaitForInput("Please enter your last name.");
  //Serial.print("Your last name is: ");
  //Serial.println(ReceivedInput);

  //Serial.println("Your Arduino is done now and will start the loop, forever doing nothing ...");  
  lcd.setCursor(16,2);
}


int num = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //lcd.write(7);
  lcd.write("Allah");
  
}
