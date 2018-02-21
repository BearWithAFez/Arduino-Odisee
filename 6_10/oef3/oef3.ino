#define K1  9
#define K2  10
#define K3  11

const byte ledArray [] = {2 ,3 ,4 ,5};
byte teller = 0;

void setup() {
  pinMode ( K1 , INPUT_PULLUP );
  pinMode ( K2 , INPUT_PULLUP ); 
  pinMode ( K3 , INPUT_PULLUP ); 
  pciSetup(K1);
  pciSetup(K2);
  pciSetup(K3);

  for(int x=0; x<=3;x++) pinMode(ledArray[x],OUTPUT);
  
}

void pciSetup ( byte pin ){
  * digitalPinToPCMSK ( pin ) |= bit (digitalPinToPCMSKbit ( pin ) ) ; // enable pin
  PCIFR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // clear any outstanding interrupt
  PCICR |= bit ( digitalPinToPCICRbit ( pin ) ) ; // enable interrupt for the group
}

ISR ( PCINT0_vect ){  
  if((!digitalRead(K1)) && (digitalRead(K2))&&(digitalRead(K3))&&(teller > 0)){
    while(!digitalRead(K1)){//antiDender
    }
    teller--;
  }
  else if((digitalRead(K1)) && (!digitalRead(K2))&&(digitalRead(K3))&&(teller < 15)){
    while(!digitalRead(K2)){//antiDender
    }
    teller++;
  }
  else if((digitalRead(K1)) && (!digitalRead(K2))&&(!digitalRead(K3))&&(teller < 15))teller = 0;
}

void loop() {      
  for(int i = 0; i < 4; i++) digitalWrite(ledArray[i], bitRead(teller,i));
}
