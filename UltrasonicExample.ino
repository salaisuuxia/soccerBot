#include "Ultrasonic.h"
Ultrasonic ultrasonic(7,8);

void setup() {
Serial.begin(9600)
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM));
  Serial.print("cm\n");
  delay(100);
}




