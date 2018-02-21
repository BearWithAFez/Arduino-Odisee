#include <EEPROM.h> // eeprom Lib
#include "Wire.h"
#define DS1307_ADDRESS 0x68
#define DS1307_MEM 0x08

void setup() {
  Serial.begin(9600);
  Serial.println("OEF3 LABO 10");
  Serial.println("Dwight Van der Velpen 2EO2");
  Serial.println("--------------------------");
  Wire.begin();
  byte adres = DS1307_MEM;
  //Write to DS
  Serial.println("Writing DS...");
  for(int i = 1; i < 61;i++){
    writeDs(i,DS1307_MEM+i);
  }
   //Reading DS
  Serial.println("Reading DS...");
  for(int i = 0; i < 16;i++){
    Serial.println(readDs(i*2));
  }
}

void loop() {
  //
}

int readDs(byte adr){
  return 
}
void writeDs(byte given, byte adr){
  
}

