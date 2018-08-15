#include"Ultrasonic.h"
#define triggerpin 7
#define echopin 4
Ultrasonic ultrasonic(triggerpin, echopin); // creating onject for class ultrasonic that was included
int leftInput=A0; //  initializing pins
int rightInput=A3;
int leftMotor=9;
int rightMotor=12;
int leftValue = 0;
int rightValue = 0;
int dist=(ultrasonic.Ranging(CM)); // calculating distance by the function
void setup()
{ 
  Serial.begin(9600); // opening serial port at 9600 baud rate
  pinMode (leftMotor, OUTPUT); // setting pin mode
  pinMode (rightMotor, OUTPUT);
 
  }

 void loop()
 {int i=random(20); // generating random numbers for totally random turns
  int ctr;
  ctr=0;
  Serial.println(i);
  float x= ultrasonic.Ranging(CM); // we calculate range again
  Serial.println("Obstacle at");
  Serial.println(x); // display of the obstacle distance
  while(x<=30 && x>=16 &&i%2==0) // while loop with cindition statement to make robot turn absolutely randomly 
  {// to turn left
    Serial.println("need to stop and find new path");
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    Serial.println("Going Left");
    digitalWrite(leftMotor, HIGH);
    x= ultrasonic.Ranging(CM);
        
  }
   while(x<=30 && x>=16 &&i%2!=0)//  while loop to make the robot turn right similar to above loop
  { Serial.println("need to stop and find new path");
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    Serial.println("Going Right");
    digitalWrite(rightMotor, HIGH);
    x= ultrasonic.Ranging(CM);     
  }

      
  while(x<16 && x>10)
    
  {
       
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);//  obstacle is too close stops for one second
    delay(1000);
    x= ultrasonic.Ranging(CM);
    ctr++;
    while(ctr==3 && i%2==0)
      {
        Serial.println("Going Left");
        digitalWrite(leftMotor, HIGH);
        delay(2000);
        ctr=0; // seeing obstacle too close, makes a right U turn
        x= ultrasonic.Ranging(CM);
        i=random(20);
        
      }
      while(ctr==3 && i%2!=0)
      {
        Serial.println("Going Right");
        digitalWrite(rightMotor, HIGH);
        delay(3000); // seeing obstacle too close makes right U turn
        ctr=0;
        x= ultrasonic.Ranging(CM);
        i=random(20);
      }
       
       
     
  }
  while(x>30)
  { 
    Serial.println("Going Forward");
    digitalWrite(leftMotor, HIGH);
    digitalWrite(rightMotor, HIGH); // if everytjing is good then move forward
    x= ultrasonic.Ranging(CM);
        
  }

    while(x<10)
  { 
    Serial.println("Object is too close, STOP!");
    digitalWrite(leftMotor, LOW);
    digitalWrite(rightMotor, LOW);
    x= ultrasonic.Ranging(CM); // if obstacle is very very close then stop
        
  }
 }//void loop closed
