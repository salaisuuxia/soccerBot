
char input[1];
int degrees;
// --------------------------------------------------------------------------- Motors
int motor_left[] = {2, 3};
int motor_right[] = {4, 5};
int motor_middle[] = {6,7};



int target_angle= 200;
int prevdir;


int IRpins[] = {0,1,2,3,4,5,10,11,12,13,14};
const int numReadings = 10;
const int numSensors = 10;
int readings[numReadings];      // the readings from the analog input

int total;                  // the running total 
int average;                // the average

int highestSensor;
int highestVal;

int cutoff = 20;

int threshHold[numSensors];
int IRval[numSensors];
int HighestVal[numSensors];


void setup()
{
   Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  
  
    // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;
  for (int i=0;i <= numSensors ;i++)
  {
    int tempSensorVal= readsensor(i);
    if (tempSensorVal > threshHold[i])
    {
      threshHold[i] =tempSensorVal;
    }
  }




for(int i = 0; i < 2; i++){
pinMode(motor_left[i], OUTPUT);
pinMode(motor_right[i], OUTPUT);
pinMode(motor_middle[i], OUTPUT);
}

}

void loop()
{
if (Serial2.available())
  {
   input[1] = Serial2.read();
   if (String(input[1]) == "h")
   {
    Serial2.println("hello. what's going wrong this time?");
   }
   else if (String(input[1]) == "w")
   {
   drive_forward();
 }
   else if (String(input[1]) == "a")
   {
   turn_left();
 }
   else if (String(input[1]) == "s")
   {
   drive_backward();
 }
   else if (String(input[1]) == "d")
   {
   turn_right();
 }
   else if (String(input[1]) == "x")
   {
     motor_stop();
 }
    else if (String(input[1]) == "q")
   {
     side_left();
 } 
   else if (String(input[1]) == "e")
   {
     side_right();
 }
   else if (String(input[1]) == "z")
   {
     side_backleft();
   }
   else if (String(input[1]) == "c")
   {
     side_backright();
   }
   
   else if (String(input[1]) == "g")        //debug compass
   {
   while (!Serial2.available())
    {  
        Serial1.print("1");
        while (!Serial1.available())
    {
    }
    degrees = Serial1.parseInt();
    Serial1.parseInt();
       delay(1000);     
       Serial2.println(degrees);

    }
    
    
   }
   
   else if (String(input[1]) == "i")
   {
     while (!Serial2.available())
    {
     IRseek(); 

    }
   }
   
      else if (String(input[1]) == "p")
   {
     while (!Serial2.available())
    {


    }
   }
   
   else if (String(input[1]) == "v")
   {
    while (!Serial2.available())
    {
      Northseek(true); 
    }
   }
   else{
     Serial2.println("i dont understand that.");
  }
  }
}


void Northseek(bool standalone)
{
      Serial1.print("1");
        while (!Serial1.available())
    {
    }
    degrees = Serial1.parseInt();
    Serial1.parseInt();
    
    
    if (degrees > target_angle + 45) 
      {
      turn_left();
      }
   else if  (degrees < target_angle - 45)   
      {
      turn_right();
      }
   else if (standalone)
   {
   motor_stop();
   }
}




void IRseek()
{
 highestSensor=0;
  highestVal=1024;
  for (int i=0;i<=numSensors;i++)
  {

      IRval[i]=readsensor(i);
    Serial.print(String(IRval[i]) + " ");
    
 
  }
  for (int i=0;i <= numSensors; i++)
  {
    if (IRval[i] < highestVal)
    {
      highestVal=IRval[i];
      highestSensor=i;
    }
  }
  Serial.print("highest Val: " + String(highestVal) + " Sensor: " + String(highestSensor) + "\n");
  if ((highestVal > cutoff) && false)
  {
    
  if (highestSensor == 0){

    drive_forward();
  }
  else if (highestSensor > 5)
  {
  turn_right();
}
  else if ( highestSensor <6)
  {
  turn_left();
  }
  
  }else{

  }

  }
  






int readsensor(int intSensorNum) {

  for (int index=0;index < numReadings;index++)
  {

    // subtract the last reading:
    total= total - readings[index];         
    // read from the sensor:  
    readings[index] = analogRead(IRpins[intSensorNum]); 

    // add the reading to the total:
    total= total + readings[index];       
    // advance to the next position in the array:  

    delay(1);        // delay in between reads for stability            

  }                      

  average = total / numReadings;    
  return(average);  

}














void motor_stop(){

  
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);

digitalWrite(motor_middle[0], LOW); 
digitalWrite(motor_middle[1], LOW);
delay(1000);
}

void drive_forward(){
  if (prevdir !=1)
  {
    prevdir =1;
     motor_stop();
   delay(100);
  }
  
    digitalWrite(11, HIGH);
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);


digitalWrite(motor_middle[0], LOW); 
digitalWrite(motor_middle[1], LOW);
}


void turn_right(){
  if (prevdir !=2)
  {
    prevdir =2;
     motor_stop();
   delay(100);
  }


digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);

digitalWrite(motor_middle[0], LOW); 
digitalWrite(motor_middle[1], HIGH);
}

void turn_left(){
  if (prevdir !=3)
  {
    prevdir =3;
     motor_stop();
   delay(100);
  }
  
  digitalWrite(13, HIGH);
  
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 


digitalWrite(motor_middle[0], HIGH); 
digitalWrite(motor_middle[1], LOW);

}

void drive_backward(){
  if (prevdir !=4)
  {
    prevdir =4;
     motor_stop();
   delay(100);
  }
  digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH);


}

void side_left()
{
  if (prevdir !=5)
  {
    prevdir =5;
     motor_stop();
   delay(100);
  }

  digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);


digitalWrite(motor_middle[0], LOW); 
digitalWrite(motor_middle[1], HIGH);



}

void side_right()
{
  if (prevdir !=6)
  {
    prevdir =6;
     motor_stop();
   delay(100);
  }

digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);


digitalWrite(motor_middle[0], HIGH); 
digitalWrite(motor_middle[1], LOW);
}


void side_backright()
{
  if (prevdir !=7)
  {
    prevdir =7;
     motor_stop();
   delay(100);
  }

  digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);


digitalWrite(motor_middle[0], HIGH); 
digitalWrite(motor_middle[1], LOW);

}

void side_backleft()
{
  if (prevdir !=8)
  {
    prevdir =8;
     motor_stop();
   delay(100);
  }

  digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH);


digitalWrite(motor_middle[0], LOW); 
digitalWrite(motor_middle[1], HIGH);

}
