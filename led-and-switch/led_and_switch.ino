#include <LiquidCrystal.h>

// reference of http://www.hiramine.com/physicalcomputing/arduino/lcd.html
LiquidCrystal g_lcd( 12, 11, 5, 4, 3, 2 );

void setup()
{
        pinMode(9, INPUT);
        pinMode(8, INPUT);
        pinMode(7, OUTPUT);
	g_lcd.begin( 16, 2 );

	g_lcd.clear();
	g_lcd.setCursor( 0, 0 );
}

int point = 0;

void loop()
{
	g_lcd.setCursor( 0, 1 );
        for (int i = 0; i < point; i++) {
            g_lcd.print(" ");
        }
        g_lcd.print("A");
        for (int i = point; i < 15; i++) {
            g_lcd.print(" ");
        }
        if (digitalRead(9) == HIGH) {
          if (point > 0) {  point -= 1; }
          g_lcd.setCursor( 0, 0 );
          g_lcd.print("      <<-      ");
          tone(7, 262, 100);
        }
        else if (digitalRead(8) == HIGH) {
          if (point < 15) { point += 1; }
          tone(7, 523, 100);
          g_lcd.setCursor( 0, 0 );
          g_lcd.print("      ->>      ");
        }
        
        delay( 100 );
}

