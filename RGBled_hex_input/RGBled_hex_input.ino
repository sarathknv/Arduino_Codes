/*Enter the HEXADECIMAL color code(proper) in the Serial monitor and watch the RGB led display the color
   Ex: #FF00AA - FF red, 00 green, AA blue
*/

int value[6]; //0, 1 for red, 2, 3 for green, 4, 5 for blue
char c;

int rPin = 11;
int gPin = 10;
int bPin = 9;


void setup() {
  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ready!");
}

void loop() {
  while (Serial.available() == 0);
  delay(100);   //give time to buffer

  getColorCode();   //sores the entered data in values[]
  setColor((value[0] * 16 + value[1]), (value[2] * 16 + value[3]), (value[4] * 16 + value[5]));
  //setColor(255, 0, 0);
}

