/*
  I2C communication protocol
  ADXL345         Arduino Uno/Nano
   GND             GND
   Vin             3.3V
   SDA             A4
   SCL             A5
   If the accelorometer is not Adafruit's then connect CS to 3.3 V
  Reference:
  http://codeyoung.blogspot.in/2009/11/adxl345-accelerometer-breakout-board.html
  http://morf.lv/modules.php?name=tutorials&lasit=31
  http://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf
  https://www.sparkfun.com/tutorials/240
  https://dl.dropboxusercontent.com/u/43421685/Website%20Content/ADXL345_single_double_tap.ino
  http://www.jarzebski.pl/arduino/czujniki-i-sensory/3-osiowy-akcelerometr-adxl345.html

  Detecting taps by constantly checking the INT_SOURCE Register
  (It worked when Single and Double Tap bits were set 1 and Watermark and Overrun bits to 0 )
*/
#include<Wire.h>

#define DEVICE (0x53)    //Device address
boolean check1 = false, check2 = false;
byte data, data2;    //stores byte read from INT_SOURCE (0x30)

void setup() {
  Wire.begin();
  Serial.begin(9600);

  writeTo(DEVICE, 0x2D, 0);           //POWER_CTL We first clear
  writeTo(DEVICE, 0x2D, 16);          //standby mode(sleep)?
  writeTo(DEVICE, 0x2D, 8);           //measure mode


  writeTo(DEVICE, 0x31, 10);  // DATA_FORMAT 10-12 bit ±8g || 11-13 bit ±16g
  init(60, 45, -127);         //offsets


  writeTo(DEVICE, 0x2A, 6);   //TAP_AXES  00000110 (x and y)|| 00000001 not detecting double tap
  writeTo(DEVICE, 0x1D, 40);  //THRESH_TAP 15.6mg/LSB   2.5g
  writeTo(DEVICE, 0x21, 32);  //DUR 625 μs/LSB     0.02sec
  writeTo(DEVICE, 0x22, 80);  //LATENT 1.25ms/LSB  0.1sec
  writeTo(DEVICE, 0x23, 240); //WINDOW 1.25ms/LSB  0.3sec

  writeTo(DEVICE, 0x2F, 32);  //INT_MAP 00100000      double to INT2
  writeTo(DEVICE, 0x2E, 96);  //INT_ENABLE 01100000
}

void loop() {
  readFrom(DEVICE, 0x30, 1, &data);   //INT_SOURCE cleared when read(to allow new values)
  //Serial.println(data, BIN);
  if ((data >> 6) & 1)
  {
    if (!((data >> 5) & 1))
    {
      Serial.println("Single Tap");
      check1 = true;
    }
    else
    {
      Serial.println("Double Tap");
      check2 = true;
    }
    
  }
  delay(200);  
  readFrom(DEVICE, 0x30, 1, &data2); 
   if (((data2 >> 6) & 1) && check2 == true)
  {
    if (!((data2 >> 5) & 1))
    {
      Serial.println("Triple Tap");
    }
    else
    {
      Serial.println("Quadruple Tap");
    }
  }
  delay(20);
  check1 = false; check2 = false;
}


