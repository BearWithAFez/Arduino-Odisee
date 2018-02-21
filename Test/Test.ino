int LED1 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1 ,OUTPUT);
  digitalWrite(LED1 ,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED1 ,HIGH);
  delay(500);
  digitalWrite(LED1 ,LOW);
  delay(500);
}
