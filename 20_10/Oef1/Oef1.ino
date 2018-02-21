char x = 33;
String deci = "";
String hexi = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("CHAR\tDEC\tHEX");
  Serial.println("-------------------");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(x <= 122){
    deci = String("\t");
    hexi = deci;
    deci += String(x,DEC);
    hexi += String(x,HEX);
    
    Serial.print(x);
    Serial.print(deci);
    Serial.println(hexi);
    
    x++;
  }
}
