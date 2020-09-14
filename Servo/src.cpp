#include <Servo.h>
Servo servo;
void buttonAngle();
const int servoPin = 5;
const int xPin = A0;
const int switchPin = 2;
int newSwitchValue;
int oldSwitchValue = 1;
int xValue;
int servoState = 1;
float angle;
int i = 0;
int j;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

xValue = analogRead(xPin);
angle = (180.0/1023.0)*xValue;
servo.write(angle);
}
