
char sensor[8]; 
int deg = 0; 
int contator = 0;
byte value = 0;
 
void setup() {
 
Serial.begin(9600);
Serial1.begin(9600);
 
}
 
void loop() {
 
measure();
 
}
 
void measure(){
 
value = 0;
 
Serial1.write(0x31);
while(value == 0){
if(Serial1.available()){
sensor[contator] = Serial1.read();
contator = (contator + 1) % 8;
if (contator == 0){
deg = (sensor[2]-48)*100 + (sensor[3]-48)*10 + (sensor[4]-48);
value = 1; 
  }
 }
}
Serial.println(deg);
}
