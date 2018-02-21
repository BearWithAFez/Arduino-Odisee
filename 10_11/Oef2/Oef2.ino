byte incomingByte;
int nr;
byte b;
const byte ledArray[] = {2,3,4,5};
bool flag = true;

void setup() {
  Serial.begin(115200,SERIAL_8O2);
  for(int x = 0; x < sizeof(ledArray); x++) {
    pinMode(ledArray[x],OUTPUT);
  }
}

void loop() {
  if(flag){
    Serial.println("Toets de letter in van uw keuze:");
    Serial.println("a. alle LED's aan");
    Serial.println("b. alle LED's uit");
    Serial.println("c. individuele LED aansturen\n");
    flag = false;
  }
  if(Serial.available() > 0) { // bytes beschikbaar?
    incomingByte = Serial.read();
    switch(incomingByte){
      case 'a':
        for(int x = 0; x < sizeof(ledArray); x++) {
          digitalWrite(ledArray[x], HIGH);
        }
        flag = true;
        break;
        
      case 'b':
        for(int x = 0; x < sizeof(ledArray); x++) {
          digitalWrite(ledArray[x], LOW);
        }
        flag = true;
        break;
        
      case 'c':
        Serial.println("geef het nummer van de LED gevolgd door A (aan) of U (uit), bv. 2A:");
        while(Serial.available() <= 0){}
        nr = Serial.read();
        if(nr < '5' && nr > '0'){
          delay(100);
          while(Serial.available() <= 0){}         
          b = Serial.read();
          switch(b){
            case 'a':        
              digitalWrite(ledArray[nr-48], HIGH);
              break;
            case 'u':          
              digitalWrite(ledArray[nr-48], LOW);
              break;
            default:
              break;
          }
        }        
        flag = true;
        break;
      default:
        flag = true;
        break;
    }
  }
}

