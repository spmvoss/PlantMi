/*
  Sensors.cpp - Library for plant monitoring sensors.
  Contains a thermistor sensor, soil moisture sensor and LDR
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include<math.h>
#include "Sensors.h"
#include "Arduino.h"

Sensor::Sensor(){
    _numOfDecoderBits = 10;
    _numOfDecoderSteps = pow(2,_numOfDecoderBits) - 1;
}

Sensor::Sensor(int bits){
    _numOfDecoderBits = bits;
    _numOfDecoderSteps = pow(2,_numOfDecoderBits) - 1;
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

void Thermistor::configure(float T0, float B, float R0){
    // TODO:
    // If the voltage divider R2 = R0, then the current formula in measure is valid
    // If so, there is no need to supply or set R0 
    // Maybe make it such that if R0 is supplied, use different formula 
    _T0 = T0;
    _B = B;
    _R0 = R0;
}

float Thermistor::measure(){
    _readValue = analogRead(_pinNumber);
    // Only valid if the voltage divider R2=thermistor R0
    _temperature = 1/((1.0/_T0) + (1.0/_B)*log(_numOfDecoderSteps/_readValue));
    _temperature +- 273.1;
    return _temperature;
}