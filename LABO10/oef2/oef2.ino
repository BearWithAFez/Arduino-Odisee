#include <EEPROM.h> // eeprom Lib

void setup() {
  Serial.begin(9600);
  Serial.println("OEF2 LABO 10");
  Serial.println("Dwight Van der Velpen 2EO2");
  Serial.println("--------------------------");
  
  //Write to EEPROM
  Serial.println("Writing Eeprom...");
  for(int i = 0; i < 16;i++){
    writeEeprom(2000+i,i*2);
  }
   //Reading
  Serial.println("Reading Eeprom...");
  for(int i = 0; i < 16;i++){
    Serial.println(readEeprom(i*2));
  }
}

void loop() {
  //
}

int readEeprom(byte adr){
  return ((EEPROM.read(adr+1) << 8) |(EEPROM.read(adr)));
}
void writeEeprom(int given, byte adr){
  EEPROM.write(adr, (given & 0xFF)); //neem lower half
  EEPROM.write(adr+1, ((given >> 8) & 0xFF)); //neem higher half (shift hoogste hoogste waarde)
}

