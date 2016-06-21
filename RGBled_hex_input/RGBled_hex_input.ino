int value[6];
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
  delay(100);

  getColorCode();
  setColor((value[0] * 16 + value[1]), (value[2] * 16 + value[3]), (value[4] * 16 + value[5]));
  //setColor(255, 0, 0);
}

