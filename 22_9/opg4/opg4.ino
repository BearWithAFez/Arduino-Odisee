  const byte ledArray [] = {2 ,3 ,4 ,5};

  void setup() {
    for(int x=2; x<=5;x++){
      pinMode(x,OUTPUT);
    }
  }

  void loop() {
    for(int x=0; x<=3;x++){
      digitalWrite(ledArray[x],HIGH);
      delay(500);
      digitalWrite(ledArray[x],LOW);
    }
  }
