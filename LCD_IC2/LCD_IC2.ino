#include <LiquidCrystal_I2C.h>

/********************************
* name:I2C LCD1602
* function:You should now see your I2C LCD1602 display the flowing characters: "SunFounder" and "hello, world".
********************************/
// include the library code
#include <Wire.h> 
/**********************************************************/
char array1[]=" SunFounder               "; //the string to print on the LCD
char array2[]="hello, world!             "; //the string to print on the LCD
int tim = 500; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
/*********************************************************/
void setup()
{
  
  //lcd.begin(16,2);
 lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  Serial.begin(9600); 
}
/*********************************************************/
void loop() 
{
lcd.setCursor(0,0);
lcd.print("YESSS");
}
/************************************************************/
