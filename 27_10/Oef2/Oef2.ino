#include <Licht.h>
Licht LED1(2);
Licht LED2(3);
Licht LED3(4);
void setup() {
  // put your setup code here, to run once:
  
  LED1.aan()
; // instantie LED1 aan
  LED2.dim(50);
  LED3.uit();
}

void loop() {
  // put your main code here, to run repeatedly: 
}
