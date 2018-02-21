  void setup() {
    for(int x=2; x<=5;x++){
      pinMode(x,OUTPUT);
    }
  }

  void loop() {
    for(int x=2; x<=5;x++){   
      digitalWrite(x,HIGH);
      delay(500);
      digitalWrite(x-1,LOW);
    }
  }
