/*
  Pump.h - Library for pump actuator.
  Can control a one-way pump and allows for setting how much ml should be pumped
  Created by Sander P.M. Voss, December 06, 2019.
  Released into the public domain.
*/
#ifndef PUMP_H
#define PUMP_H

#include "Sensors.h"

class Pump{
    private:
      int _pinNumber;
      float _litrePerHour = -1.0;
      bool _hasWaterSensor = false;
      WaterLevelSensor waterSensor;
    public:
      void setPin(int pinNumber);
      void setCapacity(float litrePerHour);
      void addWaterSensor(int pinNumber, bool reversedLogic);
      bool waterLevelOk();
      bool water();
      bool water(int milliliter);
};

#endif