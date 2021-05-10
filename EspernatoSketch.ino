#include <Servo.h> //Import the servo header
Servo panCamera, tiltCamera; //Initialize both motors
String data = "";  //Empty string to receive commands
void setup() {
    servoPan.attach(10); //Assign servos to pins
    servoTilt.attach(11);
    Serial.begin(9600); //Set baudrate of 9600
}
void loop() {
    while (Serial.available() > 0) //Check if data is received
    {
        char receivedChar = Serial.read();
        //If received character is E pan camera
        if (receivedChar == 'T') {
            servoPan.write(data.toInt());
            data = ""; // Clear string buffer
        }
        //If received character is E tilt camera
        else if (receivedChar == 'E') {
            servoTilt.write(data.toInt());
            data = ""; // Clear string buffer
        }
        else {
            data += singleChar; //Append new data to string
        }
    }
} 
