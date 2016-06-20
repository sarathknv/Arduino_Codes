#include <Servo.h>

Servo myServo;
int angle = 0;
int timePeriod = 15000;

int i = 1;

unsigned long int currentMillis;
unsigned long int prevMillis;

void setup() {
  myServo.attach(8, 550, 2350); //close to 0 and 180
  //myServo.attach(9); //default 544 and 2400

  myServo.write(angle++);
  prevMillis = 0;

}

void loop() {
  currentMillis = millis();

  if (currentMillis - prevMillis > timePeriod / 360) {
    angle = angle + i;
    myServo.write(angle);

    prevMillis = currentMillis;
    if (angle == 180) i = -1;
    if (angle == 0) i = 1;
  }




  //myServo.write(); //angle
  //myServo.detach(); //for other purpose with the pin
  //myServo.writeMicroseconds(); //specify angle in terms of pulse width(angle is mapped to pulse width)
  //myServo.read() //returns current pulse width as an angle between 0 and 180 degrees
  //myServo.readMicroseconds(); //returns current pulse width in microseconds
  //myServo.attached(); //true if attached

}

