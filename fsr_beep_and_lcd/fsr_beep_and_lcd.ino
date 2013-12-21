#include <LiquidCrystal.h>

LiquidCrystal g_lcd( 12, 11, 5, 4, 3, 2 );  // rs, enable, d4, d5, d6, d7

float R1=5.1,rf,fg;
int n, char_length;

int TONE_PIN = 8;
int LED_BLUE_PIN = 9;
int LED_YELLOW_PIN = 10;
int LED_RED_PIN = 13;

void setup()
{
  pinMode(LED_BLUE_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(TONE_PIN, OUTPUT);
  
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
  g_lcd.print("G= ");
  g_lcd.print(fg);
  
  g_lcd.setCursor( 0, 1 );
  if (int(fg) < 500){
    char_length = int(fg) / 20;
  }
  
  for(int i = 0; i < char_length; i++){
    g_lcd.print(">");
  }
  for(int i = char_length; i < 16; i++){
    g_lcd.print(" ");
  }

  
  tone(TONE_PIN, fg, 1000);
  
  if (int(fg) <= 1) {
    digitalWrite(LED_BLUE_PIN, LOW);
  }
  else {
    digitalWrite(LED_BLUE_PIN, HIGH);
  }
  
  if (int(fg) % 2 == 0) {
    digitalWrite(LED_RED_PIN, LOW);
  }
  else {
    digitalWrite(LED_RED_PIN, HIGH);
  }
  
  if (int(fg) >= 1000){
    digitalWrite(LED_YELLOW_PIN, HIGH);
  }
  else {
    digitalWrite(LED_YELLOW_PIN, LOW);
  }
  
  delay( 100 );
}
