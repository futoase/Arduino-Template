#include <LiquidCrystal.h>

LiquidCrystal g_lcd( 12, 11, 5, 4, 3, 2 );  // rs, enable, d4, d5, d6, d7

float R1=5.1,rf,fg;
int n;

void setup()
{
  Serial.begin(9600);
  g_lcd.begin( 16, 2 );	
  g_lcd.clear();	
}

void loop()
{
  n=analogRead(1);
  rf=R1*n/(1024.0-n);
  fg=880.79/rf - 0.17;
  if (fg < 0.01) {
    fg = 0;
  }
  
  g_lcd.setCursor( 0, 0 );
  g_lcd.print("n= ");
  g_lcd.print(n);
  g_lcd.print("rf= ");
  g_lcd.print(rf*1000);
  g_lcd.setCursor( 0, 1 );
  g_lcd.print("G= ");
  g_lcd.print(fg);

  delay( 100 );
}
