//change the order of bits using the the array

void changebits(byte value)
{
  byte newval;
  for (int i = 0; i < 8; i++)
  {
    bitWrite(newval, arr[i], bitRead(value, i));
  }
  leds = newval;

}

