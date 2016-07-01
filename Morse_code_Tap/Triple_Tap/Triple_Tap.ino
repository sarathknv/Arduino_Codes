/*
   Single, Double and Triple Tap detection. (By reading the INT_SOURCE Register twice)
*/
#include<Wire.h>
#define DEVICE (0x53)    //Device address

byte data;    //stores byte read from INT_SOURCE (0x30)

void setup() {
  Wire.begin();
  Serial.begin(9600);

  writeTo(DEVICE, 0x2D, 0);  //POWER_CTL We first clear
  writeTo(DEVICE, 0x2D, 16); //standby mode(sleep)?
  writeTo(DEVICE, 0x2D, 8);  //measure mode


  writeTo(DEVICE, 0x31, 10);  // DATA_FORMAT 10-12 bit ±8g || 11-13 bit ±16g
  init(60, 45, -127);         //offsets


  writeTo(DEVICE, 0x2A, 6);   //TAP_AXES  00000110 (x and y)|| 00000001 not detecting double tap
  writeTo(DEVICE, 0x1D, 50);  //THRESH_TAP 15.6mg/LSB   2.5g for 40
  writeTo(DEVICE, 0x21, 32);  //DUR 625 μs/LSB     0.02sec
  writeTo(DEVICE, 0x22, 80);  //LATENT 1.25ms/LSB  0.1sec
  writeTo(DEVICE, 0x23, 240); //WINDOW 1.25ms/LSB  0.3sec

  writeTo(DEVICE, 0x2F, 32);  //INT_MAP 00100000      double to INT2
  writeTo(DEVICE, 0x2E, 96);  //INT_ENABLE 01100000
}

void loop() {
  readFrom(DEVICE, 0x30, 1, &data);   //INT_SOURCE cleared when read(to allow new values)

  if ((data >> 6) & 1)
  { // 1
    if (!((data >> 5) & 1))
    {
      Serial.println("Single Tap");
    }
    else
    {
      delay(500);  // wait to allow another tap
      readFrom(DEVICE, 0x30, 1, &data);
      if ((data >> 6) & 1)
      {
        Serial.println("Triple Tap");
      }
      else
      {
        Serial.println("Double Tap");
      }
    } // close else
  } // close if
  delay(30);
} // close loop


