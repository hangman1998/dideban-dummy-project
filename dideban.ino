#include <LiquidCrystal.h>
#include <Keypad.h>
#include<SoftwareSerial.h>


//PA3
#define lcd_bl   41 
//PA0
#define rs       44 
//PA1
#define RW       43 
//PA2
#define EN       42 
//PA4
#define DB4      40 
//PA5
#define DB5      39 
//PA6
#define DB6      38 
//PA7
#define DB7      37 

const byte keypad_ROWS = 4; //four rows
const byte keypad_COLS = 4; //four columns

//pc 0-7
/*
byte rowPins[keypad_ROWS] = {28, 29, 30, 31}; //connect to the row pinouts of the keypad
byte colPins[keypad_COLS] = {32, 33, 34, 35}; //connect to the column pinouts of the keypad

char hexaKeys[keypad_ROWS][keypad_ROWS] = {
  {'1','2','3','f'},
  {'4','5','6','g'},
  {'7','8','9','h'},
  {'s','0','x','i'}
};
SoftwareSerial s(10,11);

Keypad main_keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, keypad_ROWS, keypad_COLS); 
*/
/*
#define EN       PA2
#define EN       PA2
*/



LiquidCrystal lcd(rs,EN, DB4, DB5, DB6, DB7);  



void setup() {
  // set up the LCD's number of columns and rows:
  DDRA=1<<3;
  PORTA=0;
  pinMode(RW,OUTPUT);
  pinMode(lcd_bl,OUTPUT);
  digitalWrite(lcd_bl,HIGH);
  digitalWrite(RW,LOW);
  lcd.begin(20, 4);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
  lcd.clear();
  unsigned int inp=analogRead(A0);
  lcd.print("DiDeban:");
  DDRB=0xFF;
  PORTB=0xff;
  
}

void loop() {
  unsigned int nn=analogRead(A0);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  
  lcd.print(millis() / 1000);
  
  lcd.setCursor(0, 2);
  lcd.print("value: ");
  lcd.print(nn);
  char key_sym = main_keypad.getKey();
  
  lcd.setCursor(0, 3);
  if (key_sym)
  {
    lcd.print(key_sym);
  }
  
  delay(400);
}
