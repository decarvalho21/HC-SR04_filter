#include "Arduino.h"
#include "HC-SR04_filter.h"

hc_filter::HC-SR04_filter(int _TrigPin, int _EchoPin)
{
	pinMode(_TrigPin, OUTPUT);
	pinMode(_EchoPin, INPUT);
	digitalWrite(_TrigPin, LOW);
	delayMicroseconds(2);
	TrigPin = _TrigPin;
	EchoPin = _EchoPin;
}
int hc_filter::getDistance()
{
	digitalWrite(TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW);
	duration = pulseIn(EchoPin, HIGH);
	if (duration < 15294)
	{
		distance = duration * 0.017;
		difdistance = distance - lastdistance;
		if (difdistance < 5 && difdistance > -5)
		{
			oscontrol++;
			if (oscontrol > 3)
			{
				return distance;
				oscontrol = 0;
			}
			else
			{
				return lastdistance;
			}
		}
	}
	else
	{
		return 0;
	}
	duration = 0;
	lastdistance = distance;
}