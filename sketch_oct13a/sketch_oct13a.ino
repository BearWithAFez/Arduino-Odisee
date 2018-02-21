const byte ledArray [] = {2 ,3 ,4 ,5};
byte buttons[] = {0,0,0};
byte loper = 1;
byte onOff = 1;


void setup() {
  // put your setup code here, to run once:

  for(int x=0; x<=3;x++){
    pinMode(ledArray[x],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 0; i < 4; i++){
    digitalWrite(ledArray[i], bitRead(loper,i));
  }

  if((loper == 1) && onOff == -1){
    loper = 8;
  }
  else if((loper == 8) && onOff == 1){
    loper = 1;
  }    
  else if(onOff =! 0){
    if(onOff == 1){
      loper= loper *2;
    }
    else{
      loper = loper /2;
    }
  }
  
  delay(500);
}
