void setup(){

  pinMode(2,OUTPUT);  //L motor
  pinMode(3,OUTPUT);

  pinMode(4,OUTPUT);  //R motor
  pinMode(5,OUTPUT);

  pinMode(6,OUTPUT);  //back motor
  pinMode(7,OUTPUT);

  pinMode(8,OUTPUT);  //backspin
  pinMode(9,OUTPUT);
  //int speed = 255; used when we have PWM

}


void loop(){
  drive_forward();
  delay(1000);
  drive_backward();
  delay(1000);
  turn_left();
  delay(1000);
  turn_right();
  delay(1000);


}

void drive_forward(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}


void drive_backward(){
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);

}

void turn_left(){
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
}

void turn_right(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}


