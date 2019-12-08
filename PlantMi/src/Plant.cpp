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

Plant::Plant(string name){
    _soilMoistureContent = -1;
    _LUX = -1;
    _soilTemperature = -1.0;
    _name = name;
}

string Plant::name(){
    return _name;
}

void Plant::changeName(string name){
    _name = name;
}

void Plant::addSoilMoistureSensor(int pin, int lowValue, int highValue){
    _soilMoistureSensor = SoilMoistureSensor(12);
    _soilMoistureSensor.setPin(pin);
    _soilMoistureSensor.configure(lowValue, highValue);
}

void Plant::addSoilTemperatureSensor(int pin, float T0, float B, float R0){
    _soilTemperatureSensor = Thermistor(12);
    _soilTemperatureSensor.setPin(pin);
    _soilTemperatureSensor.configure(T0, B, R0);
}

void Plant::addLightSensor(int pin, float slope, float offset, float dividerR, float voltage){
    _lightSensor = LightSensor(12);
    _lightSensor.setPin(pin);
    _lightSensor.configure(slope, offset, dividerR, voltage);
}

void Plant::addPump(int pin, float litrePerHour, int sensorPin = -1, bool sensorLogicReversed = false){
    _pump = Pump();
    _pump.setPin(pin);
    _pump.setCapacity(litrePerHour);
    if(sensorPin != -1){
        _pump.addWaterSensor(sensorPin, sensorLogicReversed);
    }
}

void Plant::sample(){
    cout << "Taking measurement sample for " << _name << endl << endl;
    if(_hasSoilMoistureSensor){
        _soilMoistureContent = _soilMoistureSensor.measure();
        cout << "Soil Moisture Content: " << _soilMoistureContent << "%" << endl;
    }
    if(_hasSoilTemperatureSensor){
        _soilTemperature = _soilTemperatureSensor.measure();
        cout << "Soil TemperatureL " << _soilTemperature << " Celsius" << endl; 
    }
    if(_hasLightSensor){
        _LUX = _lightSensor.measure();
        cout << "Light Intensity: " << _LUX << " LUX" << endl << endl;
    }
}