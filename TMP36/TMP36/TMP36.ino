/*TMP36 Temperature sensor
 * Reference: https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
 * Data-sheet(for connections) - http://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf
 */
int tempPin = 0;  //analog pin to be read from
unsigned int rawReading; //from pin
float tempVoltage;   //rawReading to voltage
float tempC;       //actual temp in Celcius

void setup(){
  Serial.begin(9600);
}

void loop(){
  rawRreading = analogRead(tempPin);
  tempVoltage = (rawReading*5.0)/1024;  //convert to voltage
  tempC = (tempVoltage - 0.5)*100;      //TMP36 has an offset 500mV and 10mV per degree

  Serial.print(tempVoltage);Serial.print("  ");
  Serial.println(tempC);
  delay(1000);
}

