/*Here in this code the threshold for turning on and turning off are made different. Otherwise it is pretty clear that
 * the led will flicker at the transition point.
 * Have you ever noticed the laptop display flicker like a light bulb when you hold its switch in the middle?
 * This is because the thresholds are different.
 */
//sensorValue increases with increase in light
 
#define on 450   //if < 450 switch on
#define off 500  //if > 500 turn off

const int sensorPin = 0; //analog 0
const int led = 2; 
int sensorValue = 0; //0 - 1023 read from sensorPin


void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  sensorValue = analogRead(analogPin);
  Serial.println(sensorValue);

  if(sensorValue < 450) digitalWrite(led, HIGH);
  if(sensorValue, > 500) digitalWrite(led, LOW);
}

