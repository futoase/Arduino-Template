#include <LiquidCrystal.h>

// rs, enable, d4, d5, d6, d7
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );

int LCD_COLUMNS = 16;
int LCD_ROWS = 16;
int lineOneFrame = 0;
int writeTwoPosition = 2;

void setup()
{
  lcd.begin( LCD_COLUMNS, LCD_ROWS );
  lcd.clear();
}

void writeLineOne()
{
  lcd.setCursor( 0, 0 );
  lcd.print("LCD TEST");
  switch (lineOneFrame) {
    case 0:
      lcd.print(" (^o^)) ");
      break;
    case -1:
      lcd.print("  ((^-^)");
      break;
  }
  lineOneFrame = ~lineOneFrame;
}

void writeLineTwo()
{
  lcd.setCursor( 0, 1 );
  for(int i = 0; i < writeTwoPosition; i++) {
    lcd.print(" ");
  }
  lcd.print("X"); 
  writeTwoPosition++;
  for(int i = writeTwoPosition; i < LCD_COLUMNS - writeTwoPosition; i++){
    lcd.print(" ");
  }
  if (writeTwoPosition > LCD_COLUMNS) { writeTwoPosition = 0; }
}

void loop()
{
  writeLineOne(); 
  writeLineTwo();
  delay(500);
}
