/*
  Sensors.cpp - Library for plant monitoring sensors.
  Contains a thermistor sensor, soil moisture sensor and LDR
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "Sensors.h"
#include "Arduino.h"

Sensor::Sensor(){
    // Nothing to do at initialisation
}

void Sensor::setPin(int pin){
    _pinNumber = pin;
    pinMode(_pinNumber, INPUT);
}

void SoilMoistureSensor::configure(int lowValue, int highValue){
    // Set-Up the sensor before use
    _lowValue = lowValue; // analog read value in dry soil
    _highValue = highValue; // analogRead value in soaked soil
}

int SoilMoistureSensor::measure(){
    // Performs a measurement and saves the value
    _readValue = analogRead(_pinNumber); // Read the voltage at pin
    _soilMoistureLevel = (_readValue - _lowValue)*(100.0/(_highValue - _lowValue));
    return _soilMoistureLevel; // soil moisture level 0-100%
}