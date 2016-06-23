//update the shift register by writing the new value

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW); //pull latch pin LOW to start sending data
   shiftOut(dataPin, clockPin, LSBFIRST, leds); //send data
   digitalWrite(latchPin, HIGH); //pull latch pin HIGH to stop sending data
}
