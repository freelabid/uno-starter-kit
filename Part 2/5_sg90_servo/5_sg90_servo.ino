/*
  Freelab - Servo SG90

  Menggerakkan servo SG90 sesuai nilai PWM di Arduino
  
  Rangkaian:
  - Pin input SG90 ke pin 1 Arduino
  - VCC SG90 ke +5V Arduino, GND SG90 ke GND Arduino

  https://www.intorobotics.com/tutorial-how-to-control-the-tower-pro-sg90-servo-with-arduino-uno/
*/

#include <Servo.h>
 
int servoPin = 9;
 
Servo servo;  
 
int servoAngle = 0;   // servo position in degrees
 
void setup()
{
  Serial.begin(9600);  
  servo.attach(servoPin);
}
 
 
void loop()
{
//control the servo's direction and the position of the motor

   servo.write(45);      // Turn SG90 servo Left to 45 degrees
   delay(10000);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(10000);          // Wait 1 second
   servo.write(135);     // Turn SG90 servo Right to 135 degrees
   delay(10000);          // Wait 1 second
   servo.write(90);      // Turn SG90 servo back to 90 degrees (center position)
   delay(10000);

//end control the servo's direction and the position of the motor


//control the servo's speed  

//if you change the delay value (from example change 50 to 10), the speed of the servo changes
  for(servoAngle = 0; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    servo.write(servoAngle);              
    delay(100);                  
  }

  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    servo.write(servoAngle);          
    delay(100);      
  }
  //end control the servo's speed  
}
