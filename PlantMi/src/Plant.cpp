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
#include <Arduino.h>

#include <string>
using namespace std;

Plant::Plant(string plantName) : needsWatering(_needsWatering), name(_name), LUX(_LUX), soilMoistureContent(_soilMoistureContent), soilTemperature(_soilTemperature){
    _soilMoistureContent = -1;
    _LUX = -1;
    _soilTemperature = -1.0;
    _name = plantName;
    _hasSoilTemperatureSensor = false;
    _hasSoilMoistureSensor = false;
    _hasLightSensor = false;
    _hasPump = false;
    _hasNoSensors = true;
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
    _hasNoSensors = false;
}

void Plant::addSoilTemperatureSensor(int pin, float T0, float B, float R0){
    _soilTemperatureSensor = Thermistor(12);
    _soilTemperatureSensor.setPin(pin);
    _soilTemperatureSensor.configure(T0, B, R0);
    _hasSoilTemperatureSensor = true;
    _hasNoSensors = false;
}

void Plant::addLightSensor(int pin, float slope, float offset, float dividerR, float voltage){
    _lightSensor = LightSensor(12);
    _lightSensor.setPin(pin);
    _lightSensor.configure(slope, offset, dividerR, voltage);
    _hasLightSensor = true;
    _hasNoSensors = false;
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

bool Plant::setMoistureLimit(int threshold){
    _soilMoistureThreshold = threshold;
    return true;
}

void Plant::sample(){
    if(_hasNoSensors){
        Serial.println("Plant has no sensors, doing nothing");
        return;
    }
    static int measurements[3];
    Serial.print("Taking measurement sample for: ");
    Serial.println(_name);
    if(_hasSoilMoistureSensor){
        _soilMoistureContent = _soilMoistureSensor.measure();
        _needsWatering = (_soilMoistureContent < _soilMoistureThreshold);
        Serial.print("Soil Moisture Content: ");
        Serial.print(_soilMoistureContent);
        Serial.println("%");
    }
    if(_hasSoilTemperatureSensor){
        _soilTemperature = _soilTemperatureSensor.measure();
        Serial.print("Soil Temperature: ");
        Serial.print(_soilTemperature);
        Serial.println(" Celsius");
    }
    if(_hasLightSensor){
        _LUX = _lightSensor.measure();
        Serial.print("Light Intensity: ");
        Serial.print(_LUX);
        Serial.println(" LUX");
    }
    if(_needsWatering && _hasPump){
        bool succeeded = _pump.water();
        if(!succeeded){
            // Do we trigger some sort of notification system?
            // Or make this function return a true/false based on
            Serial.print("Water level for ");
            Serial.print(_name);
            Serial.println(" too low!");
        } else {_needsWatering = false; Serial.print("Succesfully watered "); Serial.println(_name);}
    } else if (_needsWatering && !_hasPump){
        // Do nothing (let the managing class check if _needsWatering and handle accordingly)
        // Or make this trigger some sort of notification system?
    }
}

bool Plant::waterLevelOk(){
    if(_hasPump){
        return _pump.waterLevelOk();
    }
}