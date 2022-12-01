#include <Servo.h>
int potPinClamp = A0;
int potPinShoulder = A1;
int potPinElbow = A2;

Servo servoMClamp;
Servo servoMShoulder;
Servo servoMElbow;
int posClamp = 0;
int posShoulder = 0;
int posElbow = 0;

void setup() {
  Serial.begin(9600);
  servoMClamp.attach(7);
  servoMShoulder.attach(8);
  servoMElbow.attach(10);
}
void loop() {
  MoveClamp();
  MoveElbow();
  MoveShoulder();
}
void MoveClamp() {
  posClamp = analogRead(potPinClamp);
  posClamp = map(posClamp, 0, 1023, 0, 180);
  servoMClamp.write(posClamp);
  delay(15);
}
void MoveShoulder() {
  posShoulder = analogRead(potPinShoulder);
  posShoulder = map(posShoulder, 0, 1023, 0, 180);
  servoMShoulder.write(posShoulder);
  delay(15);
}
void MoveElbow() {
  posElbow = analogRead(potPinElbow);
  posElbow = map(posElbow, 0, 1023, 0, 180);
  servoMElbow.write(posElbow);
  delay(15);
}