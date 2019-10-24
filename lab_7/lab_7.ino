void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

String tekst = "hello world  This is a (fjern) sentence to test m(remove this)y program";


int a = 0;
int b = 0;

//MyString operator+(char*)
//{
//}

class MyString {
  public:
    MyString() { c == NULL; len = 0; }    
    MyString(char* s) {
      for (char* a = s; *a != 0; a++);
      len = a;
      c = new char[len];
      for (char* a = s, *b = c; *a != 0; a++, b++)
        *b = *a;
    }
    ~MyString() { delete[] c; }
    char* getString() { return c; }
  private:
    char* c;
    int len;
//  friend MyString operator+(char*);
};




void loop() {
  MyString str("test");
  Serial.println(str.getString());
  // put your main code here, to run repeatedly:
    //check(tekst);
    char *testGreier = "dette er (veldig) mo(sdfdfs)ro";
    char utenPar[50];
    removePar(testGreier, utenPar, 50);
    Serial.println(utenPar);
    //while(true);
}

void removePar(char *source, char *dest, int len)
{
  int parCount = 0;
  for (char *c = source;*c != 0;c++) {
    if (*c == '(')
      parCount++;
    else if (*c == ')')
      parCount--;
    else if (parCount == 0) {
      *dest++ = *c;
    }
  }
  *dest = '\0';
}

void check(String txt) {

  while(a != -1) {
  a = tekst.indexOf("(");
  b = tekst.indexOf(")");

  int toRemove = b - a + 1;
  tekst.remove(a, toRemove);
  }
  Serial.println(tekst);
}
