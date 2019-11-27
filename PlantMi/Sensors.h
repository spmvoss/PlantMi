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
      int _numOfDecoderBits;
      float _numOfDecoderSteps;
      int _pinNumber; // Which pin to measure
      int _readValue; // To store the reading
      float _voltageSupplied; // Working voltage
      float _voltageMeasured;
  public:
    Sensor();
    Sensor(int bits);
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

class Thermistor : public Sensor {
    private:
        int _resistor;
        float _T0; // Temperature (K) at which R0 is measured
        float _B; // Sensor's beta value
        float _R0; // Resistance at T0
        float _temperature;
    public:
        void configure(float T0, float B, float R0);
        float measure();
};

#endif