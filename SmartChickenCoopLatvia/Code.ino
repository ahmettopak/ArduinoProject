#include <Servo.h> 
//Call the Servo.H library

Servo servo1; // We define servo 1
Servo servo2; // We define servo 2

void setup()
{
  Serial.begin(9600); // We initiate communication at 9600 baud
  servo1.attach(3); // We define the input of the servo 1
  servo2.attach(6); // We define the input of the servo 2
}

void loop()
{
  int lightsensor = analogRead(A0); /* We want the light variable to be
  read from input A0 */
  
  Serial.println(lightsensor); /* We print the value received 
  by the light sensor to the screen */
  
  if (lightsensor > 500) { /* If the value of the lightsensor variable is greater than 700 */
	servo1.write(90); // Set the angle of the servo to 90
    servo2.write(180); // Set the angle of the servo to 180
  }
  
  else{ 
    servo1.write(0); // Set the angle of the servo to 0
    servo2.write(0); // Set the angle of the servo to 0
  }
}