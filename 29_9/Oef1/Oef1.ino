int rndm;
const byte ledArray [] = {2 ,3 ,4 ,5};
void setup() {
  // put your setup code here, to run once:
  for ( int x = 0; x < 4; x++) {
    pinMode (ledArray[x] , OUTPUT) ;
  }
  Serial.begin(9600);  
  randomSeed(analogRead(1));
}

void loop() {
  rndm = random(0,15);
  Serial.println(rndm); //Zodat je kan controleren op Serieel Test venster wat de waarde is 
  for(int i = 0; i < 4; i++){
   digitalWrite(ledArray[i], bitRead(rndm,i)); ;
  }
  delay(2000);

}