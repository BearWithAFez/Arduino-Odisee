#define K1  9
#define K2  10
#define K3  11

const byte ledArray [] = {2 ,3 ,4 ,5};
byte buttons[] = {0,0,0};
byte teller = 0;

void setup() {
  pinMode ( K1 , INPUT_PULLUP );
  pinMode ( K2 , INPUT_PULLUP ); 
  pinMode ( K3 , INPUT_PULLUP ); 

  for(int x=0; x<=3;x++){
      pinMode(ledArray[x],OUTPUT);
    }
  
}

void loop() {  
  buttons[0] = digitalRead(K1);
  buttons[1] = digitalRead(K2);
  buttons[2] = digitalRead(K3);
  
  if(buttons[0] + buttons[1] + buttons[2] >= 2){
    if((buttons[0] == 0) && (teller > 0)) teller--;
    else if((buttons[1] == 0) && (teller < 15)) teller++;
    else if(buttons[2] == 0) teller = 0;
    
    for(int i = 0; i < 4; i++){
       digitalWrite(ledArray[i], bitRead(teller,i));
    }
  
    delay(150);
  }
}
