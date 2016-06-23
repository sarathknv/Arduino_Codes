/*Reference: https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds?view=all 
  Turn on and off leds one by one 
*/

int latchPin = 5; //to pin 12
int clockPin = 6; //to pin 11
int dataPin = 4; //to pin 14
int outputEnablePin = 3; //to pin 13

byte leds = 0; // control the leds by writng values to this byte
 
void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}
 
void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister();
    delay(500);
  }
}

//update the shift register by writing new values
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
