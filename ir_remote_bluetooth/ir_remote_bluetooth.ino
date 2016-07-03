/*Control your T.V. with your mobile phone
   Pin 3: Irled +
   TX HC-05 - RX Arduino
   RX HC-05 - TX Arduino (3.3V, use Resistors)
   Reference: http://howtomechatronics.com/tutorials/arduino/arduino-and-hc-05-bluetooth-module-tutorial/ (for bluetooth connections)
*/
//Add volume
#include <IRremote.h>

// give channel numbers
unsigned int gemmov[4] = {1, 4, 0, 4};
unsigned int zee[4] = {1, 4, 1, 0};
unsigned int gemini[4] = {1, 4, 1, 2};
unsigned int gemcom[4] = {1, 4, 1, 4};
unsigned int etv[4] = {1, 4, 1, 7};
unsigned int maa[4] = {1, 4, 2, 3};
unsigned int maamov[4] = {1, 4, 3, 0};
unsigned int etvplus[4] = {1, 4, 4, 7};

IRsend irsend;

unsigned long int data = 0;   //to store the hex code
String text = "";            // stores input from phone

void setup() {
  Serial.begin(9600);
  Serial.println("You are ready to go!");
}

void loop() {

  //get channel via bluetooth
  while (Serial.available() > 0)
  {
    delay(30);
    char c = (char)Serial.read();
    text += c;
  }

  if (text == "gemmov")  setChannel(gemmov, (sizeof(gemmov) / sizeof(gemmov[0])));
  if (text == "zee")     setChannel(zee, (sizeof(zee) / sizeof(zee[0])));
  if (text == "gemini")  setChannel(gemini, (sizeof(zee) / sizeof(zee[0])));
  if (text == "gemcom")  setChannel(gemcom, (sizeof(gemcom) / sizeof(gemcom[0])));
  if (text == "etv")     setChannel(etv, (sizeof(etv) / sizeof(etv[0])));
  if (text == "maa")     setChannel(maa, (sizeof(maa) / sizeof(maa[0])));
  if (text == "maamov")  setChannel(maamov, (sizeof(maamov) / sizeof(maamov[0])));
  if (text == "etvplus") setChannel(etvplus, (sizeof(etvplus) / sizeof(etvplus[0])));
  if (text == "power")
    for (int j = 0; j < 3; j++)
    {
      irsend.sendRC6(0xC0000C, 24);
      delay(100);
    }
  text = "";
}

//send the signal
void setChannel(unsigned int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    switch (arr[i])
    {
      case 1: data = 0xC00001; break;
      case 2: data = 0xC00002; break;
      case 3: data = 0xC00003; break;
      case 4: data = 0xC00004; break;
      case 5: data = 0xC00005; break;
      case 6: data = 0xC00006; break;
      case 7: data = 0xC00007; break;
      case 8: data = 0xC00008; break;
      case 9: data = 0xC00009; break;
      case 0: data = 0xC00000; break;
      default: break;
    }
    for (int j = 0; j < 3; j++)
    {
      irsend.sendRC6(data, 24);
      delay(100);
    }
    delay(300);
  }
}

