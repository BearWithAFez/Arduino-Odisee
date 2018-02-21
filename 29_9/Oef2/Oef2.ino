int straal = 1;
void setup() {
  // put your setup code here, to run once:  
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Een cirkel met straal ");
  Serial.print(straal);
  Serial.print(" heeft een opervlakte van ");
  Serial.println(pow(straal, 2) * PI);
  straal++;
  delay(1000);

}
