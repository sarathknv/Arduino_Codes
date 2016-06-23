/*Reference: https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds?view=all
  Turn on and off leds one by one, control the order using the array.
  The changebits function changes the order of the bits(not in the same variable though).
*/

int latchPin = 5; //to pin 12
int clockPin = 6; //to pin 11
int dataPin = 4; //to pin 14

byte ledstemp = 0; //write value to this to control leds
byte arr[] = {7, 0, 1, 2, 3, 4, 5, 6};
byte leds; //stores updated bits

void setup()
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  ledstemp = 0;
  changebits(ledstemp); updateShiftRegister();   //use change bits before updateShiftRegister
  delay(500);

  for (int i = 0; i < 8; i++)
  {
    bitSet(ledstemp, i);
    changebits(ledstemp); updateShiftRegister();

    delay(500);
  }
}



