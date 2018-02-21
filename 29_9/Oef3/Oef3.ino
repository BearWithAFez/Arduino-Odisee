void setup() {
  // put your setup code here, to run once:
  int res[5];
  Serial.begin(9600);
  randomSeed(analogRead(1));
  for(int i = 0; i < 5; i++){
    res[i] = random(1, 20);
  }
  
  Serial.println("The lucky numbers are:");
  for(int i = 0; i < 5; i++){
    Serial.println(res[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
