/*Function to set the amount(brightness) of red, green and blue*/

void setColor(int red, int green, int blue) {
  analogWrite(rPin, red);
  analogWrite(gPin, green);
  analogWrite(bPin, blue);
  Serial.print("You are now seeing "); Serial.print("#");
  Serial.print((value[0] * 16 + value[1]), HEX);
  Serial.print((value[2] * 16 + value[3]), HEX);
  Serial.println((value[4] * 16 + value[5]), HEX);
}
