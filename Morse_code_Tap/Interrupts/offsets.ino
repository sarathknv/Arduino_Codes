/*The offset registers are each 8 bit. I used a 13 bit resoulution with 3.90625 mg/LSB, but for offset adjustment
   scale factor is 15.6 mg/LSB.
  Also z axis acceleration was around 5m/s^2 and could not be adjusted by hardware offset because z_offset was 340 and
    is out of range for a byte.
*/

void init(byte x_offset, byte y_offset, byte z_offset)
{
  writeTo(DEVICE, 0x1E, x_offset);
  writeTo(DEVICE, 0x1F, y_offset);
  writeTo(DEVICE, 0x20, z_offset);
}
