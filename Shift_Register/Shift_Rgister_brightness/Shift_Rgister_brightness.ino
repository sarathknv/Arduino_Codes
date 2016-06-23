/*Reference: https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds?view=all */

int latchPin = 5; //to pin 12
int clockPin = 6; //to pin 11
int dataPin = 4; //to pin 14
int outputEnablePin = 3; //to pin 13

byte leds = 0; // control the leds by writng values to this byte
byte b = 0;  //brightness 0 - 255
byte i = 1;
void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(outputEnablePin, OUTPUT);
}

void loop()
{
  delay(5000);
  setBrightness(0);
  for (i = 0; i < 8; i++) bitSet(leds, i);    //to change bits
  updateShiftRegister();
  delay(500);

  while (1) {
    setBrightness(b);
    b = b + i;
    if (b == 255) i = -1;
    if (b == 0) i = 1;
    delay(50);

  }
}




