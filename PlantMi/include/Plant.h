/*
  Plant.h - Library for plant class
  Plant with name, type, requirements, sensors, and actuators
  Created by Sander P.M. Voss, December 07, 2019.
  Released into the public domain.
*/

#ifndef PLANT_H
#define PLANT_H

#include "Sensors.h"
#include "Pump.h"

#include <string>
using namespace std;

class Plant {
    private:
      string _name;
      SoilMoistureSensor _soilMoistureSensor;
      Thermistor _soilTemperatureSensor;
      LightSensor _lightSensor;
      Pump _pump;

      int _soilMoistureContent;
      int _LUX;
      float _soilTemperature;
      
      bool _hasSoilMoistureSensor;
      bool _hasSoilTemperatureSensor;
      bool _hasLightSensor;
      bool _hasPump;      
    public:
      Plant(string name);
      void changeName(string name);
      string name();
      void addSoilMoistureSensor(int pin, int lowValue, int highValue);
      void addSoilTemperatureSensor(int pin, float T0, float B, float R0);
      void addLightSensor(int pin, float slope, float offset, float dividerR, float voltage);
      void addPump(int pin, float litrePerHour, int sensorPin, bool sensorLogicReversed);
      void sample();
};

#endif