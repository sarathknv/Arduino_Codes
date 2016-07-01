/*
   Single, Double and Triple Tap detection. (By reading the INT_SOURCE Register twice)
*/
#include<Wire.h>
#define DEVICE (0x53)    //Device address
#define num_bits 3    //number of bits for val

byte data = 0;        //stores byte read from INT_SOURCE (0x30)
byte i = 0, val = 0;  // val - value outputted by taps

unsigned long int currentMillis = 0, prevMillis = 0;  //This is for detecting inactivity. Hardware(inbuilt) isn't working, either single tap or activity is being detected but not both.

void setup() {
  Wire.begin();
  Serial.begin(9600);

  writeTo(DEVICE, 0x2D, 0);  //POWER_CTL We first clear
  writeTo(DEVICE, 0x2D, 16); //standby mode(sleep)?
  writeTo(DEVICE, 0x2D, 8);  //measure mode

  writeTo(DEVICE, 0x31, 10);  // DATA_FORMAT 10-12 bit ±8g || 11-13 bit ±16g
  init(60, 45, -127);         //offsets

  writeTo(DEVICE, 0x2A, 6);   //TAP_AXES  00000110 (x and y)|| 00000001 not detecting double tap
  writeTo(DEVICE, 0x1D, 50);  //THRESH_TAP 15.6mg/LSB   2.5g for 40
  writeTo(DEVICE, 0x21, 32);  //DUR 625 μs/LSB     0.02sec
  writeTo(DEVICE, 0x22, 80);  //LATENT 1.25ms/LSB  0.1sec
  writeTo(DEVICE, 0x23, 240); //WINDOW 1.25ms/LSB  0.3sec

  writeTo(DEVICE, 0x2F, 32);  //INT_MAP 00100000      double to INT2
  writeTo(DEVICE, 0x2E, 96);  //INT_ENABLE 01101000
}

void loop() {
  readFrom(DEVICE, 0x30, 1, &data);   //INT_SOURCE cleared when read(to allow new values)
  //Serial.println(data, BIN);

//Detect tap and make changes in the bit
  if ((data >> 6) & 1)        // if Single tap is detected
  {
    if (!((data >> 5) & 1))   // if Double tap is not detected
    {  
      //Serial.println("1");       
      bitSet(val, i);        //1 for Single tap
    }
    else
    {
      //Serial.println("0");   //0 for Double tap
    }    
    prevMillis = millis();
    i++;
  }
  
//Printout val 
  if(i == num_bits)
  {
    Serial.print("value = "); Serial.println(val);    
    val = 0; i = 0;    
  }
  
//Check for inactivity 
  currentMillis = millis();
  if(currentMillis - prevMillis > 3000)
  {
    val = 0; i = 0;
  }

//Remove noise   
  if ((data >> 6) & 1)   //if any tap has been detected previously
  {
    for (int i = 0; i < 20; i++)readFrom(DEVICE, 0x30, 1, &data);   //This is to suppress any trailing noise which may be detected as a tap
  }
  delay(50);
}

