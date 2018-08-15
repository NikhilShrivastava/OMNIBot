#include "Ultrasonic.h"
#define triggerpin 7
#define echopin 4
Ultrasonic ultrasonic(triggerpin, echopin); // creating object of ultrasonic class that we included
int leftInput=A0;
int rightInput=A3;// inintializing pins
int leftMotor=9;
int rightMotor=12;
int leftValue = 0;
int rightValue = 0;
int dist=(ultrasonic.Ranging(CM)); // calculating distance
void setup()
{ Serial.begin(9600);
  pinMode (leftMotor, OUTPUT);// setting pin behaviour to output
  pinMode (rightMotor, OUTPUT);
 }
void loop()
{
  dist=(ultrasonic.Ranging(CM)); // calculating distsnce and storing to dist in cm
  

if(dist>35) // robot will only move forward if distance is more than 35 cm this value is changeble
{
  dist=(ultrasonic.Ranging(CM));
  leftValue = analogRead (leftInput);
  rightValue= analogRead (rightInput);
  Serial.println(leftValue);
  Serial.println("left value ^");
  Serial.println(rightValue);
  Serial.println("right value ^");
if ( leftValue < 600 && rightValue < 600 ) // if both sensors read black then stop
   {Serial.println("Stop");
     digitalWrite (leftMotor, LOW);
     digitalWrite (rightMotor, LOW);
   }
   else
{

     if
     ( leftValue > 600 && rightValue < 600 && dist > 25 )  // left sensor on black turn right
    {
      Serial.println("Turn Right");
      if(dist>25){
      digitalWrite (leftMotor, LOW);
      digitalWrite (rightMotor, HIGH);
      dist=(ultrasonic.Ranging(CM));
      }
    }
 else{
   if (leftValue < 600 && rightValue > 600 && dist > 25  ) // right sensor on black turn left
   {Serial.println("Turn Left");
   if(dist>25){
   digitalWrite (rightMotor, LOW);
   digitalWrite (leftMotor, HIGH);
   dist=(ultrasonic.Ranging(CM));
   }
   }
   else
   {
     if (leftValue > 600 && rightValue > 600 && dist > 25)// if both on white move forward
     {if(dist>25){
      Serial.println("Go Forward");
      digitalWrite (rightMotor, HIGH);
      digitalWrite (leftMotor, HIGH);
      dist=(ultrasonic.Ranging(CM));
     }
     }
   }
  }
 }

dist=(ultrasonic.Ranging(CM));}
else
{// if dist less than 35 i.e. some obstacle is on path then stop
  Serial.println("Stop by Ultrasonic");
  digitalWrite (leftMotor, LOW);
  digitalWrite (rightMotor, LOW);}
}
