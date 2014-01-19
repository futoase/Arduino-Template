#include <SPI.h>
#include <SD.h>

#define FSR_PIN 0

const int chipSelect = 4;

void setup()
{
  Serial.begin(9600);
   while (!Serial) {
    ;
  }

  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");
}

void loop()
{
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.println(String(getFSR()));
    dataFile.close();
    Serial.println(String(getFSR()));
  }
  else {
    Serial.println("error opening datalog.txt");
  } 
}

float getFSR()
{
  int iValue = analogRead( FSR_PIN );
  double dV = iValue * 5.0 / 1023;
  double dR = -1.0;
  if( 0.005 < (5.0 - dV) )
  {
    dR = 10 * 1000 * dV / (5.0 - dV);
  }
  return dR;
}
