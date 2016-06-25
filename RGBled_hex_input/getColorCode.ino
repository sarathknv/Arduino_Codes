/*I don't know why if I enter 3 characters in Serial monitor, it is always followed by space and a new line character.
   This did not happen for data sent over bluetooth.
*/
void getColorCode() {

  if (Serial.available() > 9 || Serial.available() < 9) {      //one character for # and last two for space and newline
    Serial.println("Invalid code!");
  }
  else {
    c = Serial.read();       //ignore #
    for (int i = 0; i < 6; i++) {
      c = Serial.read();
      switch (c)
      {
        case 'F': value[i] = 15; break;
        case 'E': value[i] = 14; break;
        case 'D': value[i] = 13; break;
        case 'C': value[i] = 12; break;
        case 'B': value[i] = 11; break;
        case 'A': value[i] = 10; break;
        default: value[i] = (int)c - '0'; break;
      }
    }
    while(Serial.available() > 0) c = Serial.read();  //clear the buffer
  }



}
