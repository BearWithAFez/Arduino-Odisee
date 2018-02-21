#include <EEPROM.h> // eeprom Lib
#include <avr/pgmspace.h>
const char signMessage[] PROGMEM  = {"I AM YOUR ARDUINO, TAKE ME TO YOUR LEADER!"};

void setup() {
  Serial.begin(9600);
  Serial.println("OEF4 LABO 10");
  Serial.println("Dwight Van der Velpen 2EO2");
  Serial.println("--------------------------");
  
  int len = strlen_P(signMessage);
  for (int k = 0; k < len; k++)
  {
    char myChar =  pgm_read_byte_near(signMessage + k);
    Serial.print(myChar);
  }
}
void loop() {
  //
}

