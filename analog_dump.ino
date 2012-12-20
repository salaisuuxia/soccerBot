void setup(){
Serial.begin(9600);
}

void loop(){

for (int i=0; i<16;i++)
  {
    Serial.print(analogRead(i));
    Serial.print(" ");
  }
  Serial.print("\n");
  
}
