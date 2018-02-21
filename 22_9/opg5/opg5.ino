const byte ledArray [] = {2 ,3 ,4 ,5};
int x;
int richting;

void setup() {
  for(int x=2; x<=5;x++){
    pinMode(x,OUTPUT);
  }
  richting = 1;
}

void loop() {
    digitalWrite(ledArray[x],HIGH);
    delay(500);
    digitalWrite(ledArray[x],LOW);
    x += richting;
    if((x==3)||(x==0)){
      richting *= -1;
    }
}
