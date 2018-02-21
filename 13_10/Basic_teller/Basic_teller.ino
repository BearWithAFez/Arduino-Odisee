#include <TimerOne.h>

#define K1  9   //knop1(rechts)
#define K2  10  //knop2(midden)
#define K3  11  //knop3(links)

bool ledsStand = false;
const byte ledArray[] = {2,3,4,5};

void setup() {
  Timer1.initialize (500000); //aantal µs voor interupt. 1000= 1ms. 1000000=1s.
  Timer1.attachInterrupt(timerIsr); //zeg dat als de timer vol is dat je een interupt mag oproepen.
  Serial.begin (9600);

  for(int x = 0; x < 4;x++){
    pinMode(ledArray[x], OUTPUT);
  }  
}

void timerIsr () {
  if(ledsStand){
    ledsStand = false;
  }else{
    ledsStand = true;
  }
  Serial.println("de Leds zijn ge-toggled");
}

void loop() {      
  for(int x = 0; x < 4;x++){
    digitalWrite(ledArray[x], ledsStand);
  }  
}
