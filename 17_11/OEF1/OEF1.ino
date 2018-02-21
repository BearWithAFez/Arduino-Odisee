#include <Streaming.h>
#include <Wire.h>
#include <TTSDisplay.h>
#include <TTSLight.h>

TTSDisplay disp;                                    // instantiate an object of display
TTSLight light;                                     // instantiate an object of light sensor
const int waarde[] = {190,500,800,1000};
const byte ledArray [] = {2 ,3 ,4 ,5};

void setup()
{
    for(int x=2; x<=5;x++){
      pinMode(x,OUTPUT);
    }
}

void loop()
{
    int valLight = light.get();                     // get light sensor value    
    disp.num(valLight);                             // display light sensor value
    
    for(int i = 0; i < 4; i++){
      if(valLight <= waarde[i]){
        digitalWrite(ledArray[i],HIGH);
      }
      else{
        digitalWrite(ledArray[i],LOW);
      }
    }
    
    delay(100);
}
