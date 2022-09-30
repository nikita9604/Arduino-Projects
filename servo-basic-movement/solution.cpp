#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // rotation
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // rotation
    myservo.write(pos);
    delay(15); 
  }
}
