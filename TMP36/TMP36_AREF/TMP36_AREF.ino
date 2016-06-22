/*Using TMP36 Temperature sensor with AREF pin on arduino for more precision
 * Reference: https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
 *            http://tronixstuff.com/2013/12/12/arduino-tutorials-chapter-22-aref-pin/
 * Data-sheet(for connections): http://www.analog.com/media/en/technical-documentation/data-sheets/TMP35_36_37.pdf           
 */

 
#define AREF_voltage 3.3
int tempPin = 0;  //analog pin to be read from
unsigned int rawReading; //from pin
float tempVoltage;   //rawReading to voltage
float tempC;       //actual temp in Celcius

void setup(){
  Serial.begin(9600);
  analogReference(EXTERNAL);
  //analogReference(DEFAULT);  //in case you want to revert back to board's voltage.
}

void loop(){
  rawReading = analogRead(tempPin);
  tempVoltage = (rawReading * (AREF_voltage))/1024;  //convert to voltage
  tempC = (tempVoltage - 0.5)*100;      //TMP36 has an offset 500mV and 10mV per degree

  Serial.print(tempVoltage);Serial.print("  ");
  Serial.println(tempC);
  delay(1000);
}

