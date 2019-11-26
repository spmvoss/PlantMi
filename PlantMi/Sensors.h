/*
  Sensors.h - Library for plant monitoring sensors.
  Contains a thermistor sensor, soil moisture sensor and LDR
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#ifndef Sensors_h
#define Sensors_h

// Generic sensor class forms the base of all sensors
class Sensor{
  protected: 
      int _pinNumber; // Which pin to measure
      int _readValue; // To store the reading
  public:
    Sensor();
    void setPin(int pinNumber); // Setting the pin
};

// Measures the soil moisture content
class SoilMoistureSensor : public Sensor {
  private:
    int _lowValue; // Value at 0%
    int _highValue; // Value at 100%
    int _soilMoistureLevel;
  public:
    void configure(int lowValue, int highValue);
    int measure();
};

#endif