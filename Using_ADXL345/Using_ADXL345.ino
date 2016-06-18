/*
 I2C communication protocol
 ADXL345         Arduino Uno/Nano
   GND             GND
   Vin             3.3V
   SDA             A4
   SDO             A5
*/
#include<Wire.h>

#define DEVICE (0x53)    //Device Address
const int numBytes = 6;  //Number of bytes to receive(two bytes for each axis)

byte values[6];          //To store the data received
int rawx,rawy,rawz;      

typedef struct{
  double x;
  double y;
  double z;
}accel;

accel a;

void setup(){
  Wire.begin();
  Serial.begin(9600);

  writeTo(DEVICE, 0x2D, 0);
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);
  writeTo(DEVICE, 0x31, 11);
}

void loop(){
  readFrom(DEVICE, 0x32, numBytes, values);
  rawx = (((int)values[1]) << 8) | values[0];
  rawy = (((int)values[3]) << 8) | values[2];
  rawz = (((int)values[5]) << 8) | values[4];

a.x = rawx*0.00390625;
a.y = rawy*0.00390625;
a.z = rawz*0.00390625;

  Serial.print(a.x, 4); Serial.print("  "); 
  Serial.print(a.y, 4); Serial.print("  "); Serial.println(a.z, 4);
  delay(30);
}




