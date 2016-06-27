//Read value at a register

void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device); //start transmission to device
  Wire.write(address);            //sends address to read from
  Wire.endTransmission();         //end transmission

  Wire.beginTransmission(device); //start transmission to device
  Wire.requestFrom(device, num);  // request 6 bytes from device

  int i = 0;
  while (Wire.available())
  {
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission(); //end transmission
}
