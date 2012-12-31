#include "Ultrasonic.h"
Ultrasonic rightUS(22,23);
Ultrasonic middleUS(24,25);
Ultrasonic leftUS(26,27);

void setup() {
Serial.begin(9600);
}

void loop()
{
  Serial.print("right: ");
  Serial.print(rightUS.Ranging(CM));
  delay(10);
  Serial.print(" middle: ");
  Serial.print(middleUS.Ranging(CM));
  delay(10);
  Serial.print(" left: ");
  Serial.print(leftUS.Ranging(CM));
  Serial.print("\n");

  delay(100);
}

