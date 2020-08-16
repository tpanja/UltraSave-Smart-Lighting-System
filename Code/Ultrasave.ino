/* 
  Sketch generated by the Arduino IoT Cloud Thing "IoT-UltraSave-Thing"
  https://create.arduino.cc/cloud/things/6eccd169-6d49-4487-8330-fb59d19d1909 

  Arduino IoT Cloud Properties description

  The following variables are automatically generated and updated when changes are made to the Thing properties

  bool userInRoom;

  Properties which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
  
  Created by Tanay Panja: Arduino IoT Ultrasave Project
  Efficient and automated smart light for energy conservation!
*/

#include "thingProperties.h"

// Initialize pin numbers to all devices as constants
const int echo_pin = 13;
const int trig_pin = 14;
const int ledCon = 5;
const int photoRes = A0;
int in = 0;
double dur = 0;
int dist = 0;
int light = 0;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
  // Set devices as input/output
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(ledCon, OUTPUT);
  pinMode(photoRes, INPUT);
}

void loop() {
  // Get measurements from ultrasonic sensor
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  dur = pulseIn(echo_pin, HIGH);
  dist = 0.034 * dur / 2;
  
  // Algorithm to turn on or off the external light, based on the ultrasonic readings
  if (dist <= 30) {

    if (userInRoom == LOW){
      //Serial.println("check1");
      userInRoom = HIGH;
    }
    else {
      if (userInRoom == HIGH){
        //Serial.println("check2");
        userInRoom = LOW;
      }
    }
    
  }
  // Display any useful information such as ultrasonic readings and weather the user is in the room or not
  digitalWrite(ledCon, userInRoom);
  
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.print(" User in room: ");
  Serial.println(userInRoom);
  
  // Important to wait 
  delayMicroseconds(100000);
}








