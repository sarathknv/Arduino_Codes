
//Writing value to a given register

void writeTo(int device, byte address, byte val) {
   Wire.beginTransmission(device); //start transmission to device 
   Wire.write(address);            // send register address
   Wire.write(val);                // send value to write
   Wire.endTransmission();         //end transmission
}
