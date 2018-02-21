#include <TimerOne.h>

#define K3  11

byte dimWaarde = 0;
byte buttons[] = {0,0,0};
const int LED = 5;

void setup() {
  
  pinMode(LED ,OUTPUT);
  pinMode ( K1 , INPUT_PULLUP );
  pinMode ( K2 , INPUT_PULLUP ); 
  pinMode ( K3 , INPUT_PULLUP ); 
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);
  
  Timer1.initialize (30000) ; //30ms
  Timer1.attachInterrupt(timerIsr);
  Serial.begin (9600) ;
  
}

ISR ( PCINT0_vect ){
    buttons[0] = digitalRead(K1);
    buttons[1] = digitalRead(K2);
    buttons[2] = digitalRead(K3);
    
    if(buttons[0] + buttons[1] + buttons[2] >= 2){
      if((buttons[0] == 0) && (dimWaarde<247)){
        while(digitalRead(K1)== 0){
        }
          dimWaarde+=13;    
      }
      else if(buttons[1] == 0) dimWaarde=0;
      else if((buttons[2] == 0) && (dimWaarde>0)){
        while(digitalRead(K3)==0){
        }
        dimWaarde-=13;
      }
    }
}

void pciSetup ( byte pin ){
  * digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // enable interrupt for the group
}

void timerIsr () {  
  analogWrite(LED, dimWaarde);
}

void loop() {      
}
