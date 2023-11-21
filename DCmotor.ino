/*
This is the DC motor with Joystick program.

Goal: To control a DC motor (speed and direction) using a joystick module. (L293D IC used as motor driver)

Main Theme: Understanding IC + map function + Analog Output (analogWrite)
*/

// Here we decalred a constant variable named "IN01" and assigned it to pin 3 of Arduino.
#define IN01 3
// Here we decalred a constant variable named "IN02" and assigned it to pin 2 of Arduino.
#define IN02 2
// Here we decalred a constant variable named "PWM" and assigned it to pin 5 of Arduino.
#define PWM 5
// Here we decalred a constant variable named "JoyX" and assigned it to pin A0 of Arduino (analog input 0).
#define JoyX A0
// Here we decalred a constant variable named "JoyY" and assigned it to pin A1 of Arduino (analog input 1).
#define JoyY A1 

void setup() 
{
  // This line tells the Arduino that pin 3 works as an output pin.
  pinMode(IN01, OUTPUT);
  // This line tells the Arduino that pin 2 works as an output pin.
  pinMode(IN02, OUTPUT);
  // This line tells the Arduino that pin 5 works as an output pin.
  pinMode(PWM, OUTPUT);
}

void loop() 
{
  // Here we declared and integer variable called "Speed" and stored within it whatever value the Arduino analog input pin 1 reads.
  int Speed = analogRead(JoyY);
  // This line "maps" the potentiometer bit values into designated PWM bit values.
  // For some reason the PWM bit value cannot be lower than 200 or else the motor will not work (too little juice/power)
  Speed = map(Speed, 0, 1023, 200, 255);
  // Here we declared and integer variable called "Direction" and stored within it whatever value the Arduino analog input pin 0 reads.
  int Direction = analogRead(JoyX);
  // This line "maps" the potentiometer bit values into values from 0 to 2 and 1 being neutral.
  // This is later combined with an IF statement to be able to control the direction.
  Direction = map(Direction, 0, 1023, 0, 2);
  
// IF direction value is equal to 0 (joystick to right hand side position)...
if (Direction == 0)
{
  // suppply no voltage to pin 3.
  digitalWrite(IN01, 0);
  // Supply 5V to pin 2.
  // This makes the motor turn counter clockwise.
  digitalWrite(IN02, 1);
  // Supply voltage proportional to PWM bit values. (controling speed of motor)
  analogWrite(PWM, Speed);
}
// But IF direction is equal to 2 (joystick to left hand side position)...
else if (Direction == 2)
{
  // Supply 5V to pin 3.
  digitalWrite(IN01, 1);
  // suppply no voltage to pin 2.
  // This makes the motor turn clockwise.
  digitalWrite(IN02, 0);
  // Supply voltage proportional to PWM bit values. (controling speed of motor)
  analogWrite(PWM, Speed);  
}
// And IF the direction value is 1 (joystick neutral position)... 
else
{
  // suppply no voltage to pin 3.
  digitalWrite(IN01, 0);
  // suppply no voltage to pin 2.
  digitalWrite(IN02, 0);
  // Set motor speed at 0 (No Motion)
  analogWrite(PWM, 0);
}
}
