/*
This is the Servo Motor with Joystick program.

Goal: To control a servo motor with a joystick.

Main Theme: Analog Input (joystick) + Analog Output (Servo) + map function.
*/

// Here we included the Servo Motor library.
#include <Servo.h>

// create servo object to control a servo.
Servo myservo;

// Here we declared an integer variable called "potentiometer" and assigned it to the Analog Input pin 0 of the Arduino.
int potentiometer = A0;

void setup() 
{
  // Here we are attaching the Servo motor to pin 9 of the Arduino. (You could also write: int Servo = 9;)
  myservo.attach(9);
  // This line tells the Arduino that pin 9 (Servo) works as an output pin.
  pinMode(9, OUTPUT);
}

void loop() 
{
  // Here we declared an integer variable called "value" and gave it the values of whatever A0 (potentiometer) pin reads.
  int Value = analogRead(potentiometer);
  // Here we map the values of the potentiometer to the desired values in degrees. 
  //(potentiometer values are from 0 to 671 and not from 0 to 1023 because it's a 5k ohm potentiometer and not 10k) 
  Value = map(Value, 0, 671, 0, 180);
  // Here we tell the Arduino to "analoglWrite" the mapped values within the Value variable onto pin 9. (You could also write: analogWrite(Servo, Value);)
  myservo.write(Value);
  // Here we freeze the program for 15 milliseconds for less lag.
  delay(15);
}
