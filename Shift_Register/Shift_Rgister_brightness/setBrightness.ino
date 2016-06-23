//function to set the brightness

void setBrightness(byte brightness) // 0 to 255
{
  analogWrite(outputEnablePin, 255 - brightness);   //This 13th pin is active low, if it is HIGH all pins are made off
}
