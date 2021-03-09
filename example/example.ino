#include <HC-SR04_filter.h>

int distance;

//(Trig_pin, Echo_pin)
HC-SR04_filter sensor(7, 6);

void setup() {
  //start serial
  Serial.begin(9600);
}

void loop() {
  //assign the sensor measurement in centimeters to the variable 'distance'
  distance = sensor.getDistance();

  //print the value
  Serial.print("Distance in cm: ")
  Serial.println(distance);
}
