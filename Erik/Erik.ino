void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRC=B11111111;
}

int liste[8];


void loop() {
  // put your main code here, to run repeatedly:
  //b10101010
  //PORTC = B00000001
 int a = 1;
 int *b = a;

  
  light();
  lightup();
}

void light() {
  
  String inp = "B10101010";
  Serial.println("starter light");
  for(int i = 1; i <= 8; i++) {
    //Serial.println(inp[i]);
    Serial.println("i for loop med int: " + String(i));
  if (String(inp[i]) == "1"){
    Serial.println("i if statement");
    switch(i){
            delay(500);
      case 1:
        PORTC = B1000000;
        liste[1] = 1;
      break;
      case 2:
       PORTC = B0100000;
       liste[2] = 1;
      break;
      case 3:
        PORTC = B0010000;
        liste[3] = 1;
      break;
      case 4:
       PORTC = B00010000;
       liste[4] = 1;
      break;
      case 5:
        PORTC = B001000;
        liste[5] = 1;
      break;
      case 6:
       PORTC = B0000100;
       liste[6] = 1;
      break;
      case 7:
        PORTC = B0000010;
        liste[7] = 1;
      break;
      case 8:
       PORTC = B0000001;
       liste[8] = 1;
      break;
      default:
      Serial.println("i SWITCH");
      break;
    }
    }else{
      liste[i] == 0;
    }
    
  }
}
void lightup(){
  String byt = "B12345678";
  for (int i = 1; i <= 8;i++){
    byt[i] = String(liste[i]);
      Serial.println(byt);
  }

}
