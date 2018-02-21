#include <TimerOne.h>

#define K1  9
#define K2  10
#define K3  11

long   teller[] = {0,0};

void setup() {
  Timer1.initialize (1000) ;
  Timer1.attachInterrupt(timerIsr);
  Serial.begin (9600) ;
  
}

void timerIsr () {
  teller[0]++ ;
}

void loop() {      
  delay(1);
  teller[1]++;

  if(teller[0]%1000 == 0){
    Serial.print("timer: ");
    Serial.println(teller[0]);
    
    Serial.print("delay: ");
    Serial.println(teller[1]);
    
    Serial.println();
  }
}
