/*https://learn.adafruit.com/using-an-infrared-library?view=all */
#include <IRremote.h>

int recv_pin = 11;

IRrecv irrec(recv_pin);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrec.enableIRIn();
}

void loop(){
  if(irrec.decode(&results)){
    Serial.println(results.value);
  }
}

//irsend.sendRaw(rawCodes, codeLen, 38);
