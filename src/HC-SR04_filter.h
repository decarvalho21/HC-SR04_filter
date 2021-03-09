#ifndef HC-SR04_filter_H
#define HC-SR04_filter_h

#include "Arduino.h"

class HC-SR04_filter
{
public:
	HC-SR04_filter(int _TrigPin, int _Echopin);
	int getDistance();
private:
	long duration;
	int distance;
	int difdistance;
	int lastdistance;
	int TrigPin;
	int EchoPin;
	int oscontrol;
};

#endif