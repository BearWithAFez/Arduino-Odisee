int straal = 1;
void setup() {
  // put your setup code here, to run once:  
  pinMode(2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2 ,HIGH);
  pow(straal, 2) * PI;
  digitalWrite(2 ,LOW);
  straal++;
  delay(1000);

}
