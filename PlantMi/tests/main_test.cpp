/*
  Arduino.cpp - A test to validate the library
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "../Sensors.h"
#include <iostream>

using namespace std; 

int main(){
    SoilMoistureSensor soilSensor; // Initialise a soil sensor
    soilSensor.setPin(14); //Set the pin to 14
    soilSensor.configure(20, 1065); // Configure the low and high value
    cout << soilSensor.measure() << endl; // Output a measurement
}