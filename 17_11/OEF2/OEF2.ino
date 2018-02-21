#include <Streaming.h>
#include <Wire.h>
#include <TM1636.h>
#include <TTSTemp.h>

TM1636 tm1636(7,8);
TTSTemp temp;                                       // instantiate an object of temperature
int8_t waarde[]= {0,0,18,12};
float grenzen[] = {27.0f ,28.0f};
float hys = 0.5f;
const byte ledArray [] = {2 ,3 ,4 ,5};

void setup()
{
    for(int x=2; x<=5;x++){
      pinMode(x,OUTPUT);
    }
    tm1636.init();
}

void loop()
{
    float valTemp = temp.get();      
    waarde[0] = (int)valTemp / 10;
    waarde[1] = (int)valTemp % 10;
    
    tm1636.display(waarde);                              // display light sensor value

    if(valTemp > grenzen[0]+ hys){
      digitalWrite(ledArray[0],LOW);
    }
    if(valTemp < grenzen[0]- hys){
      digitalWrite(ledArray[0],HIGH);
    }      
    if(valTemp > grenzen[1] + hys){
      digitalWrite(ledArray[1],HIGH);
    }
    if(valTemp < grenzen[1] - hys){
      digitalWrite(ledArray[1],LOW);
    }
    delay(100);
}
