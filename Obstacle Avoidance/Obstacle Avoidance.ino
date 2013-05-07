#include <AFMotor.h>
#include <NewPing.h>

#define TRIGGER_PIN  A0  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A2  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

 //speed variables for the left and right motor
int Lspeed = 180;
int Rspeed = 255;

//declaring the left and right motors and attaching them to 
//their corresponding connector on the motor shield
AF_DCMotor leftMotor(1, MOTOR12_64KHZ);
AF_DCMotor rightMotor(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(115200);
  //sets initial speed
  leftMotor.setSpeed(Lspeed);
  rightMotor.setSpeed(Rspeed);
}

void loop() {
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  unsigned int CM = uS / US_ROUNDTRIP_CM;
  
  if (CM < 15 && CM > 0) {
    int iteration = 0;
    while( iteration == 0){
      leftMotor.run(FORWARD);
      rightMotor.run(BACKWARD);
      iteration = 1;
    }
    delay(600);
  }
  
  //starts motors going forward
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
  
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}
