/*
  Sensors.cpp - Library for plant monitoring sensors.
  Contains a thermistor sensor, soil moisture sensor and LDR
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include <math.h>
#include "Sensors.h"
#include "Arduino.h"

Sensor::Sensor(){
    _numOfDecoderBits = 12;
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

SoilMoistureSensor::SoilMoistureSensor() : Sensor(){
}

SoilMoistureSensor::SoilMoistureSensor(int bits) : Sensor(bits){
}

void SoilMoistureSensor::configure(int lowValue, int highValue){
    // Set-Up the sensor before use
    _lowValue = lowValue; // analog read value in dry soil
    _highValue = highValue; // analogRead value in soaked soil
}

int SoilMoistureSensor::measure(){
    // Performs a measurement and saves the value
    _readValue = analogRead(_pinNumber); // Read the voltage at pin
    if (_readValue <= _lowValue){
        return 0;
    } else if (_readValue >= _highValue){
        return 100;
    } else {
        _soilMoistureLevel = (_readValue - _lowValue)*(100.0/(_highValue - _lowValue));
        return _soilMoistureLevel; // soil moisture level 0-100%
    }
}

Thermistor::Thermistor() : Sensor(){}

Thermistor::Thermistor(int bits): Sensor(bits){
}

void Thermistor::configure(float T0, float Beta, float R0){
    // TODO:
    // If the voltage divider R2 = R0, then the current formula in measure is valid
    // If so, there is no need to supply or set R0 
    // Maybe make it such that if R0 is supplied, use different formula 
    _T0 = T0;
    _Beta = Beta;
    _R0 = R0;
}

float Thermistor::measure(){
    _readValue = analogRead(_pinNumber);
    // Only valid if the voltage divider R2=thermistor R0
    _temperature = 1/((1.0/_T0) + (1.0/_Beta)*log(_numOfDecoderSteps/_readValue));
    _temperature -= 273.1;
    return _temperature;
}

LightSensor::LightSensor() : Sensor() {}

LightSensor::LightSensor(int bits) : Sensor(bits) {
}

void LightSensor::configure(float slope, float offset, float dividerR, float voltage){
    _slope = slope;
    _offset = offset;
    _dividerR = dividerR;
    _voltageSupplied = voltage;
}

float LightSensor::measure(){
    _readValue = analogRead(_pinNumber);
    _voltageMeasured = _readValue * (_voltageSupplied/_numOfDecoderSteps);
    _ldrR = _dividerR * (_voltageSupplied/_voltageMeasured) - _dividerR;
    _LUX = pow(_ldrR, _slope) * pow(10.0, _offset);
    return _LUX;
}

WaterLevelSensor::WaterLevelSensor() : Sensor(){
    _reverseLogic = true;
}

WaterLevelSensor::WaterLevelSensor(bool reverseLogic) : Sensor(){
    _reverseLogic = reverseLogic;
}

bool WaterLevelSensor::measure(){
    _waterLevelOK = digitalRead(_pinNumber);
    if(_reverseLogic){
        _waterLevelOK = !_waterLevelOK;
    }
    return _waterLevelOK;
}