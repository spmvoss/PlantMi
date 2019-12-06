/*
  Pump.cpp - Library for pump actuator.
  Can control a one-way pump and allows for setting how much ml should be pumped
  Created by Sander P.M. Voss, December 06, 2019.
  Released into the public domain.
*/

#include "Pump.h"
#include "Arduino.h"
#include "Sensors.h"

void Pump::setPin(int pinNumber){
    _pinNumber = pinNumber;
    pinMode(_pinNumber, OUTPUT);
}

void Pump::setCapacity(float litrePerHour){
    _litrePerHour = litrePerHour;
}

void Pump::addWaterSensor(int pinNumber, bool reversedLogic){
    waterSensor = WaterLevelSensor(reversedLogic);
    waterSensor.setPin(pinNumber);
    _hasWaterSensor = true;
}

bool Pump::waterLevelOk(){
    if(!_hasWaterSensor){
        throw "This pump does not have a water sensor!";
    }
    return waterSensor.measure();
}

bool Pump::water(){
    water(200);
}

bool Pump::water(int milliliter){
    // Calculate required duration of the watering cycle
    // Duration will be in milliseconds
    if(_litrePerHour == -1.0){
        throw "Pump's capacity (litres/hour) not set!";
    }
    int duration = milliliter/(_litrePerHour/(3600.0));
    if(_hasWaterSensor && waterLevelOk()){
        digitalWrite(_pinNumber, HIGH);
        delay(duration);
        digitalWrite(_pinNumber, LOW);
        return true;
    } else if (!_hasWaterSensor){
        digitalWrite(_pinNumber, HIGH);
        delay(duration);
        digitalWrite(_pinNumber, LOW);
        return true;
    } else {
        return false;
    }
}