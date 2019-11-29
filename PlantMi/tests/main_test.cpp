/*
  Arduino.cpp - A test to validate the library
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "../Sensors.h"
#include <iostream>
#include "../Arduino.h"

using namespace std; 

int main(){
    WaterLevelSensor waterSensorOne;
    waterSensorOne.setPin(13);
    cout << "Water Level one Ok: " << waterSensorOne.measure() << endl;
    WaterLevelSensor waterSensorTwo(false);
    waterSensorTwo.setPin(13);
    cout << "Water Level one Ok: " << waterSensorTwo.measure() << endl;
}