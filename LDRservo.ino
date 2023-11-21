/*
This is the Servo motor with LDR program.

Goal: To control a servo motor using a light detecting resistor sensor.

Main Theme: Analog Input + map function + myservo.write function.
*/

// Here we include the Servo motor librabry. 
#include <Servo.h>
// Here we defined a variable called "LDR" assigned to the analog input pin 0 of the Arduino. (This is our sensor)
#define LDR A0
// create servo object to control a servo.
Servo myservo;

void setup() 
{
  // This line enables printing on the serial monitor.
  Serial.begin(9600);
  // Here we are attaching the Servo motor to pin 9 of the Arduino. (You could also write: int Servo = 9;)
  myservo.attach(9);
}

void loop() 
{
  // Here we create an interger variable called "BitVal" and stored whitin it whatever A0 (LDR) pin reads.
  int BitVal = analogRead(A0);
  // Here we map the values of the LDR sensor to the desired values in degrees and store it within an integer variable called "Angle".
  // The angle values are between 0 degrees (When light) to 180 (when dark).
  int Angle = map(analogRead(A0), 0, 1023, 0, 180);
  // Here we map the values of the LDR sensor to the desired values in ohms and store it within an integer variable called "Resistance".
  // The resistance value is between 500ohm (When light) and 25koms (when dark).
  int Resistance = map(analogRead(A0), 0, 1023, 500, 25000);
  // Here we map the values of the LDR sensor to the desired values in volts and store it within a float variable called "Voltage".
  // The voltage value is between 1 (when light) to 5 volts (when dark).
  float Voltage = map(analogRead(A0), 0, 1023, 1.0, 5.0);
  // This line tells the servo motor to turn depending on the angle we recieve after the mapping of the bit value of analog input.  
  myservo.write(Angle);
  // This line freezes the whole program for 15 milliseconds (for smoothness).
  delay(15);

  // Here we print the words: "Bit Value = " to the Serial monitor.
  Serial.print("Bit Value = ");
  // Here we print the values stored within our "BitVal" variable.
  Serial.println(BitVal);
  // This line freezes the whole program for half a second.
  delay(500);
  // Here we print the words: "Voltage = " to the Serial monitor.
  Serial.print("Voltage = ");
  // Here we print the values stored within our "Voltage" variable.
  Serial.println(Voltage);
  // This line freezes the whole program for half a second.
  delay(500);
  // Here we print the words: "LDR Resistance = " to the Serial monitor.
  Serial.print("LDR Resistance = ");
  // Here we print the values stored within our "Resistance" variable.
  Serial.println(Resistance);
  // This line freezes the whole program for half a second.
  delay(500);
}
