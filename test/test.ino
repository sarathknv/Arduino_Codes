
int values[6];
char c;
void getColorCode(){
  Serial.println(Serial.available());
  if(Serial.available() > 7 || Serial.available() < 7){
    Serial.println("Invalid code!");
  }
  else{
    for(int i = 0; i < 6; i++){
      c = Serial.read();
      switch(c)
     {
      case 'F': values[i] = 15; break;
      case 'E': values[i] = 14; break;
      case 'D': values[i] = 13; break;
      case 'C': values[i] = 13; break;
      case 'B': values[i] = 13; break;
      case 'A': values[i] = 13; break;
      default: values[i] = (int)c - '0';break;
     }
    }
     
     
  }
  
 
  
}
void setup(){
  Serial.begin(9600);
  Serial.println("Ready!");
  
}

void loop(){
  while(Serial.available() == 0);
//Serial.flush();
delay(100);
Serial.println(Serial.available());
Serial.println(Serial.available());
Serial.println(Serial.available());
delay(100);
//c = Serial.read();
while(Serial.available()> 0){
  c = Serial.read();//Serial.println(Serial.available());
 // c = Serial.read();Serial.println(Serial.available());
 // c = Serial.read();
 Serial.flush();
  Serial.println(Serial.available());
  Serial.println(c);//Serial.println("hey");
}
//  getColorCode();
//  Serial.println(values[0]);
  while(1);
}

