// test serial lib of getting string.

int bufSize = 256;
char inData[256];
char inChar;
byte index=0;

void setup() {
  Serial.begin(9600);
  Serial.write("setup");
}

void loop() {
  if (Comp("m1 on")==0) {
    Serial.write("Motor 1 -> Online\n");
  }
  if (Comp("m1 off")==0) {
    Serial.write("Motor 1 -> Offline\n");
  }
}

// reffering to http://forum.arduino.cc/index.php/topic,45629.0.html
char Comp(char* This) {
  while (Serial.available() > 0) {
    if(index < bufSize){
      inChar = Serial.read();
      inData[index] = inChar;
      index++;
      inData[index] = '\0';
    }
  }

  if (strcmp(inData,This)  == 0) {
    for (int i = 0;i < bufSize; i++) {
      inData[i] = 0;
    }

    index = 0;
    return(0);
  }
  else {
    return(1);
  }
}
