

byte counter = 1;

void setup() {
  Serial.begin(9600);

}

void loop() {
  
 Serial.print(bitRead(counter, 0));
 Serial.println(!bitRead(counter, 0));
 
}

