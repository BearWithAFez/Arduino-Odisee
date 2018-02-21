#include <TM1636.h>
TM1636 tm1636(7,8);
int8_t a[4];
int incoming;

void setup() {
  tm1636.init();
  Serial.begin(115200,SERIAL_8O2);
}

void loop() {
  Serial.println("Toets in aub:");
  while(Serial.available() <= 0) {} // bytes beschikbaar?
  incoming = Serial.parseInt();
  //???? Wat krijg je eruit 
  
  if(incoming <= 9999 && incoming >= 0){
    for(int j = 0; j < 4; j++){
      a[j] = bitRead(incoming, j); //??? elke bit apart lezen en opslaan als een Uint        
    }
    tm1636.display(a);
  }
  else{
    for(int i = 0; i < 4; i++){
      a[i] = 0;
    }
    for(int i = 0; i < 3; i++){
      delay(500);
      tm1636.point(POINT_ON);
      tm1636.display(a);
      delay(500);
      tm1636.point(POINT_OFF);
      tm1636.display(a);
    }
  }
}

