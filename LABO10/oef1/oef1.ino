#include <EEPROM.h> // eeprom Lib

void setup() {
  Serial.begin(9600);
  Serial.println("OEF1 LABO 10");
  Serial.println("Dwight Van der Velpen 2EO2");
  Serial.println("--------------------------");
  
  byte SRAM[1024];//Sram array

  //Write to EEPROM
  for(int addr = 0; addr < 10; addr++){
    EEPROM.write(addr, addr+1);
  }

  //Write to SRAM
  for(int addr = 0; addr < 10; addr++){
    SRAM[addr] = addr+1;
  }

  //Individual writes
   EEPROM.write(1030, 100);
   SRAM[2054] = 100;


   //Reading
  Serial.println("Reading Eeprom...");
  for(int addr = 0; addr < 10; addr++){
    Serial.println((int)EEPROM.read(addr));
  }
  Serial.println("");
  Serial.println("Reading SRAM...");
  for(int addr = 0; addr < 10; addr++){
    Serial.println(SRAM[addr]);
  }
  Serial.println("");
  Serial.println("Reading EEPROM(1030)...");
  Serial.println(EEPROM.read(1030));
  Serial.println("");
  Serial.println("Reading SRAM[2054]...");
  Serial.println(SRAM[2054]);
  /*
   * wegens EEPROM = 1024 bits zal 1030 overlappen en dus schrijven op locatie 6
   */
}

void loop() {
  //
}
