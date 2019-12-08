/*
  Plant.h - Library for plant class
  Plant with name, type, requirements, sensors, and actuators
  Created by Sander P.M. Voss, December 07, 2019.
  Released into the public domain.
*/

#include<iostream>

#include "Plant.h"
#include "Sensors.h"
#include "Pump.h"

#include <string>
using namespace std;

Plant::Plant(string name) : needsWatering(_needsWatering){
    _soilMoistureContent = -1;
    _LUX = -1;
    _soilTemperature = -1.0;
    _name = name;
    _hasSoilTemperatureSensor = false;
    _hasSoilMoistureSensor = false;
    _hasLightSensor = false;
    _hasPump = false;
}

string Plant::name(){
    return _name;
}

void Plant::changeName(string name){
    _name = name;
}

void Plant::addSoilMoistureSensor(int pin, int lowValue, int highValue, int threshold){
    _soilMoistureSensor = SoilMoistureSensor(12);
    _soilMoistureSensor.setPin(pin);
    _soilMoistureSensor.configure(lowValue, highValue);
    _soilMoistureThreshold = threshold;
    _hasSoilMoistureSensor = true;
}

void Plant::addSoilTemperatureSensor(int pin, float T0, float B, float R0){
    _soilTemperatureSensor = Thermistor(12);
    _soilTemperatureSensor.setPin(pin);
    _soilTemperatureSensor.configure(T0, B, R0);
    _hasSoilTemperatureSensor = true;
}

void Plant::addLightSensor(int pin, float slope, float offset, float dividerR, float voltage){
    _lightSensor = LightSensor(12);
    _lightSensor.setPin(pin);
    _lightSensor.configure(slope, offset, dividerR, voltage);
    _hasLightSensor = true;
}

void Plant::addPump(int pin, float litrePerHour, int sensorPin = -1, bool sensorLogicReversed = false){
    _pump = Pump();
    _pump.setPin(pin);
    _pump.setCapacity(litrePerHour);
    if(sensorPin != -1){
        _pump.addWaterSensor(sensorPin, sensorLogicReversed);
    }
    _hasPump = true;
}

void Plant::sample(){
    cout << "Taking measurement sample for " << _name << endl << endl;
    if(_hasSoilMoistureSensor){
        _soilMoistureContent = _soilMoistureSensor.measure();
        _needsWatering = (_soilMoistureContent < _soilMoistureThreshold);
        cout << "Soil Moisture Content: " << _soilMoistureContent << "%" << endl;
    }
    if(_hasSoilTemperatureSensor){
        _soilTemperature = _soilTemperatureSensor.measure();
        cout << "Soil Temperature: " << _soilTemperature << " Celsius" << endl; 
    }
    if(_hasLightSensor){
        _LUX = _lightSensor.measure();
        cout << "Light Intensity: " << _LUX << " LUX" << endl << endl;
    }
    if(_needsWatering && _hasPump){
        bool succeeded = _pump.water();
        if(!succeeded){
            // Do we trigger some sort of notification system?
            // Or make this function return a true/false based on
            cout << "I could not water " << _name << ", water level low!" << endl;
        } else {_needsWatering = false; cout << "Succesfully watered " << _name << endl;}
    } else if (_needsWatering && !_hasPump){
        // Do nothing (let the managing class check if _needsWatering and handle accordingly)
        // Or make this trigger some sort of notification system?
    }
}