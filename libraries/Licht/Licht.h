/*
  Licht.h - Library om Leds aan te sturen.
  Created by Dwight vdv.
*/

#ifndef Licht_h
#define Licht_h
#include <Arduino.h>
class Licht
{
public:
	Licht(int pin);
	void aan();
	void uit();
	void dim(int dw);
private:
	int _pin;
};
#endif