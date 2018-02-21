#include <TM1636.h>
TM1636 tm1636(7,8);
int8_t a[4] = {1,2,3,4};

void setup() {
  // put your setup code here, to run once:
  tm1636.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  tm1636.point(POINT_ON);
  tm1636.display(a);
  delay(500);
  tm1636.point(POINT_OFF);
  tm1636.display(a);
}
