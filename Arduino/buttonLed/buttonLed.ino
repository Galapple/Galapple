int LEDState=0;
int LEDPin=8;
int buttonPin=12;
int buttonNew;
int buttonOld = 1;
void setup() {
 Serial.begin(9600);
 pinMode(LEDPin, OUTPUT);
 pinMode(buttonPin, INPUT);
}

void loop() {
  buttonNew = digitalRead(buttonPin);
  Serial.println(buttonNew);
  if (buttonOld==0 && buttonNew==1){
    if(LEDState==0) {
  digitalWrite(LEDPin, HIGH);
  LEDState=1;
  }
  else{
  digitalWrite(LEDPin, LOW);
  LEDState=0;  
  } 
  }
    buttonOld=buttonNew;
}
