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
    soilSensor.setPin(10); //Set the pin to 14
    soilSensor.configure(20, 1065); // Configure the low and high value
    cout << "Soil Moisture: " << soilSensor.measure() << endl; // Output a measurement
    Thermistor soilTemperatureSensor; // Initialise a soil sensor
    soilTemperatureSensor.setPin(11);
    soilTemperatureSensor.configure(289.0,1440.0,10000.0);
    cout << "Soil Temperature: " << soilTemperatureSensor.measure() << endl; // Output a measurement
}