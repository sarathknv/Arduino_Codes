//function to set the brightness

void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(outputEnablePin, brightness);
}
