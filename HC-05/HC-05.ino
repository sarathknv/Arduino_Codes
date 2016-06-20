#include <SoftwareSerial.h>

SoftwareSerial SerialBT(2, 3); // TX | RX

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino is ready");
  SerialBT.begin(9600);
}

void loop()
{
  //if(SerialBT.available() > 0) delay(1000);
  while (SerialBT.available() > 0) {   
    delay(30);
    Serial.print(SerialBT.readString());
    if (SerialBT.available() == 0)Serial.println("");
  }
  if (Serial.available())
  {
    SerialBT.write((char)Serial.read());
  }
}
