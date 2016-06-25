/*
  I2C communication protocol
  ADXL345         Arduino Uno/Nano
   GND             GND
   Vin             3.3V
   SDA             A4
   SDO             A5
  Reference:
  http://codeyoung.blogspot.in/2009/11/adxl345-accelerometer-breakout-board.html
  http://morf.lv/modules.php?name=tutorials&lasit=31
  http://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf

*/
#include<Wire.h>

#define DEVICE (0x53)    //Device Address
const int numBytes = 6;  //Number of bytes to receive(two bytes for each axis)

byte values[6];          //To store the data received
int rawx, rawy, rawz;

typedef struct {
  double x;
  double y;
  double z;
} accel;
accel a;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  writeTo(DEVICE, 0x2D, 0);
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);
  writeTo(DEVICE, 0x31, 10);  // 11 for 13 bit resolution and ±16 g
  init(60, 45, -127);
}

void loop() {
  readFrom(DEVICE, 0x32, numBytes, values);
  rawx = (((int)values[1]) << 8) | values[0];
  rawy = (((int)values[3]) << 8) | values[2];
  rawz = (((int)values[5]) << 8) | values[4];

  
  /*Serial.print(rawx); Serial.print("    ");
  Serial.print(rawy); Serial.print("    ");*/ Serial.print(rawz); Serial.println("    ");
  
  a.x = rawx * 0.00390625;
  a.y = rawy * 0.00390625;
  a.z = rawz * 0.00390625;

  //Serial.print(a.x, 4); Serial.print("  ");
  //Serial.print(a.y, 4); Serial.print("  "); Serial.println(a.z, 4);
  delay(30);
}




