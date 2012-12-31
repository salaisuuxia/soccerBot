

int readings[3];


void setup(){
  Serial.begin(9600);
  Serial.println("Start");
}

void loop(){
for (int i=12;i<16;i++)
  {
  readings[i-12]=ReadLegoSensor(i); // we read the raw value of the sensor
  Serial.print("Raw value: " + i);
  Serial.println(raw); // and print it to the monitor
  byte percent=map(raw, 0, 1024, 0, 100); // we convert raw to percent
  Serial.print("Percent value: " + i);
  Serial.println(percent); // and print it to the monitor
  }
}


int ReadLegoSensor(int sensorPin){
  pinMode(sensorPin, OUTPUT); //set pin as output
  digitalWrite(sensorPin, HIGH); //set output high
  delay(10); // wait a bit
  pinMode(sensorPin, INPUT); //set pin as input
  int value=analogRead(sensorPin); //read the input
  return value; //return the raw value
}
