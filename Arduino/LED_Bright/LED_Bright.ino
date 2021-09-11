int buttonPin1=12;
int buttonPin2=11;
int buttonVal1;
int buttonVal2;
int dt = 250;
int LEDbright = 0;
int LEDPin=3;
int buzzPin = 2;
void setup() {
 Serial.begin(9600);
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 pinMode(LEDPin, OUTPUT);
 pinMode(buzzPin, OUTPUT);

}

void loop() {
buttonVal1=digitalRead(buttonPin1);
buttonVal2=digitalRead(buttonPin2);
Serial.println("Button 1 = ");
Serial.println(buttonVal1);
Serial.println("Button 2 = ");
Serial.println(buttonVal2);
delay(dt);
if (buttonVal1==0){
  LEDbright=LEDbright+5;
}
if (buttonVal2==0){
  LEDbright=LEDbright-5;
}
if (LEDbright>255){
  LEDbright=255;
  digitalWrite(buzzPin, HIGH);
  delay(dt);
  digitalWrite(buzzPin, LOW);
}
if (LEDbright<0){
  LEDbright=0;
   digitalWrite(buzzPin, HIGH);
   delay(dt);
   digitalWrite(buzzPin, LOW);
}

analogWrite(LEDPin, LEDbright);
}
