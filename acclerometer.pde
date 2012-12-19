#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int xAxis = A0;
int yAxis = A1;
int zAxis = A2;
int axisValue = 0;

void setup() {
	analogReference(EXTERNAL);

}

void loop() {
  lcd.clear();
  axisValue = analogRead(xAxis);    
  lcd.print(axisValue);
  
  axisValue = analogRead(yAxis);    
  lcd.print(",");
  lcd.print(axisValue);
	

  axisValue = analogRead(zAxis); 
  lcd.print(",");	

  lcd.print(axisValue);
  
  delay(200);                 
}