#include <Servo.h>
#include "Ultrasonic.h"

Servo myServo; 

static unsigned int degreeOfMovement = 180;   
static unsigned int myServoPin = 7;
static unsigned int myUSPin = 6;

Ultrasonic myUSsensor(myUSPin);

void setup() {
  myServo.attach(myServoPin);
  Serial.begin(9600);
}

void loop() {

   unsigned long rangeInCM = myUSsensor.MeasureInCentimeters();
  Serial.println(rangeInCM);

 if (rangeInCM >= 3) {
   myServo.write(180);
 } else if (rangeInCM <=3) {
   myServo.write(0);
 } else (rangeInCM =0); {
   myServo.write(0);
 }
}
