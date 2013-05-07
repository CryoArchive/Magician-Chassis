#include <AFMotor.h>

int iterations = 0;

int Mspeed = 255;

AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);

void setup() {
  leftMotor.setSpeed(Mspeed);
  rightMotor.setSpeed(Mspeed);
}

void loop () {
  while( iterations == 0) {
    leftMotor.run(FORWARD);
    rightMotor.run(BACKWARD);
    iterations = 1;
  }
  delay(600);
  if ( iterations == 1) {
    leftMotor.run(RELEASE);
    rightMotor.run(RELEASE);
  }
}

