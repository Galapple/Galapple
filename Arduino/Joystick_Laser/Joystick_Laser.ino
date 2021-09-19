// Two servos will control a laser
#include <Servo.h>
Servo Xservo;
Servo Yservo;
int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int XSpin = 9;
int YSpin = 10;
int WVx;
int WVy;
int buzzPin = 7;
int Xval;
int Yval;
int Sval;
int dt = 200;
void setup() {
  Serial.begin(9600);
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(Spin, INPUT);
  pinMode(XSpin, OUTPUT);
  pinMode(YSpin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(Spin, INPUT);
  Xservo.attach(XSpin);
  Yservo.attach(YSpin);
  }
void loop() {
  Xval = analogRead(Xpin);
  WVx = (180./1023.)*Xval;
  Yval = analogRead(Ypin);
  WVy = (180./1023.)*Yval;
  Sval = analogRead(Spin);
  
  Xservo.write(WVx);
  Yservo.write(WVy);

  if (Sval == 0){
    digitalWrite(buzzPin, HIGH); }
  else {
    digitalWrite(buzzPin, LOW);  }
  
  delay(dt);
  Serial.print("X value = ");
  Serial.print(Xval);
  Serial.print("Y value = ");
  Serial.print(Yval);
  
}
