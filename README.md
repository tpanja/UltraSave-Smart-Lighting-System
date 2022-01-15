# UltraSave-Smart-Lighting-System
An Arduino IoT-based project, for smart lighting called Ultrasave. A mission to conserve energy in what may seem "basic situations"

# Input/Output
The MKR Wifi 1010 was used as the microcontroller. Ultrasonic sensors were used to detect a moving person, entering/exiting a room. On the first time, if the ultrasonic sensor detects the person moving by, the signal will go to the IoT board. It will turn on a signal to an output device called a "relay" to turn on an external light of high voltage. On the second time the ultrasonic sensor detects a person, it is assumed that the person has exited the room so the signal to the relay will be turned off.

# Requirements

Arduino's Cloud-based IDE was used to create the program, to input all the wifi details and thing Properties. This program works only for IoT devices.

# Code Location
Go to Code/Ultrasave.ino

Thanks,
tpanja
