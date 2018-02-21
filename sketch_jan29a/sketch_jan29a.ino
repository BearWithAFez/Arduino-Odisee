const byte ledArray [] = {2 ,3 ,4 ,5};
int led;

void setup() {
  // put your setup code here, to run once:
  for ( int x = 0; x < sizeof(ledArray); x ++) {
    pinMode(x , OUTPUT );
  }
  led = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  if(led == sizeof(ledArray)){
    led = 0;
  }
  digitalWrite(ledArray[led], HIGH);
  delay(200);
  digitalWrite(ledArray[led], LOW);
  led++;
}
