/*Reference: http://www.codeproject.com/Articles/144606/Arduino-Platform-Working-with-Shift-Registers */

int latchPin = 5; //to pin 12
int clockPin = 6; //to pin 11
int dataPin = 4; //to pin 14


byte arr[] = {128, 1, 2, 4, 8, 16, 32, 64};   //order has been changed because last led is first
byte i = 1;
byte counter = 0;

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
 
}

void loop(){

  updateShiftRegister(arr[counter]);
  delay(100);
  counter = counter + i;
  if(counter == 7) i = -1;
  if(counter == 0) i = 1;
}

