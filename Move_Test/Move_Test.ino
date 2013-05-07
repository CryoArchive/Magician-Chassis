// Motor Shield library file
#include <AFMotor.h>

AF_DCMotor motor1(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motor2(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

void setup() {
  // the speed can be set anywhere between 200 and 255
  motor1.setSpeed(255);     
  motor2.setSpeed(255);    
}

void loop() {
  // moves the motors forward. Other options include BACKWARD
  // and RELEASE which stops the motors
  motor1.run(FORWARD);
  motor2.run(FORWARD);     
}
