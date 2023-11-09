/*
  Purpose: Basic example of a 180deg Micro Servo connected via a Seead Screw Terminal
  Notes: 
    1. Connect to a Digital Pin
    2. 180 Degree ROM 0-180 values
  Author:  Ben Jones 13/7/23
  Contact: benjmain.jones21@det.nsw.edu.au
  Source: https://wiki.seeedstudio.com/Grove-Servo/
*/

#include <Servo.h>
#include "Ultrasonic.h"

Servo myServo;  // create servo object to control a servo

static unsigned int degreeOfMovement = 180;    // variable to read the value from the analog pin
static unsigned int myServoPin = 7;
static unsigned int myUSPin = 6;

Ultrasonic myUSsensor(myUSPin);

void setup() {
  myServo.attach(myServoPin);
  myServo.write(0);
  delay(100);
  Serial.begin(9600);
  Serial.println("SM Working");
  Serial.println("------------------");
}

void loop() {

   unsigned long rangeInCM = myUSsensor.MeasureInCentimeters();
  Serial.println(rangeInCM);
 
 if (rangeInCM >= 10) {
   myServo.write(180);
 } else if (rangeInCM <=20) {
   myServo.write(360);
 } else {
   myServo.write(0);
 }
}
