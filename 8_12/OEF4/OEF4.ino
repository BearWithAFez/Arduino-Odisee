#include "Wire.h"
#define DS1307_ADDRESS 0x68
#define K1 9 //K1 verbonden met pin 9
#define K2 10 //K2 verbonden met pin 10
#define K3 11 //K3 verbonden met pin 11
#define AM 1

#define PM 0
#define sec 58
#define minu 59
#define uur 11
#define weekDag 1
#define dag 10
#define maand 11
#define jaar 96

void setup() {
    Wire.begin();
    Serial.begin(9600);
    setTime(sec, minu, uur, PM, weekDag, dag, maand, jaar);
    Serial.println(" OEF3 - Dwight vdv");
    Serial.println("-------------------");
}

void loop() {
    byte second, minute, hour, ampm, weekDag, dag, maand, jaar;

    getTime(&second, &minute, &hour, &ampm, &weekDag, &dag, &maand, &jaar);
    Serial.print(hour, DEC);
    Serial.print(":");
    Serial.print(minute, DEC);
    Serial.print(":");
    Serial.print(second, DEC);
    Serial.print(" ");
    if (ampm == AM) {
        Serial.print("AM");
    }
    else if (ampm == PM) {
        Serial.print("PM");
    }
    Serial.print(" -- ");
    Serial.print(weekdag, DEC);
    Serial.print(" ");
    Serial.print(dag, DEC);
    Serial.print(" ");
    Serial.print(maand, DEC);
    Serial.print(" ");
    Serial.print(jaar, DEC);
    Serial.print(" ");
    
    //Serial.print(ampm);
    Serial.println();  
    delay(1000);
}

//Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
    return((val / 10 * 16) + (val % 10));
}

//Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
    return((val / 16 * 10) + (val % 16));
}

//Sets the time on the ds1307, Starts the clock, Sets hour mode to 24 hour clock
void setTime(byte second, byte minute, byte hour, byte ampm, byte weekDag, byte dag, byte maand, byte jaar) {
    byte temp;
    
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0);
    Wire.write(decToBcd(second));
    Wire.write(decToBcd(minute));
    temp = decToBcd(hour);
    
    bitSet(temp,  6);
    if (ampm == PM) { 
        bitSet(temp, 5);
    }
    else {
       bitClear(temp ,5);
    }
    
    Wire.write(decToBcd(temp));
    Wire.write(decToBcd(weekDag));
    Wire.write(decToBcd(dag));
    Wire.write(decToBcd(maand));
    Wire.write(decToBcd(jaar));
    Wire.endTransmission();
}

//Gets the time from the ds1307
void getTime(byte *second, byte *minute, byte *hour, byte *ampm, byte *weekDag, byte *dag, byte *maand, byte *jaar) {
    byte temp;
    
    // Reset the register pointer
    Wire.beginTransmission(DS1307_ADDRESS);
    Wire.write(0);
    Wire.endTransmission();
    
    Wire.requestFrom(DS1307_ADDRESS, 7);
    
    *second = bcdToDec(Wire.read() & 0x7f);
    *minute = bcdToDec(Wire.read());
    temp = Wire.read();          
    *hour = bcdToDec(temp & 0x1f); //mask bits 5 thru 7 for 12 hour clock
    if (bitRead(temp, 5) == PM) { //if bit 5 set, time is PM 
        *ampm = PM; 
    }
    else{
        *ampm = AM; 
    } 
    *weekDag = bcdToDec(Wire.read());
    *dag = bcdToDec(Wire.read());
    *maand = bcdToDec(Wire.read());
    *jaar = bcdToDec(Wire.read());
}


