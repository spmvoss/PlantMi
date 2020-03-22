/*
  Monitor.cpp - Library for monitor class
  Can contain multiple plant classes and will handle the monitoring and reporting
  Created by Sander P.M. Voss, March 09, 2020.
  Released into the public domain.
*/

#include "Monitor.h"
#include <Arduino.h>


PlantMonitor::PlantMonitor(const char* name) : _mqtt(name){
  _numPlants = 0;
  _maxPlants = 3;
  _interval = 2*1000;
  _lastMonitored = millis();
  _mqttEnabled = false;
}

void PlantMonitor::enableMQTT(const char* ssid, const char* password, const char* host){
  _mqtt.connect(ssid, password, host);
  _mqttEnabled = true;
}

void PlantMonitor::setID(int id){
    _ID = id;
}

void PlantMonitor::createPlant(string name){
  if(_numPlants<_maxPlants){
    plants[_numPlants].changeName(name);
    _numPlants = _numPlants + 1;
  } else{
    Serial.println("You have already reached the maximum number of plants!");
  }
}

void PlantMonitor::setInterval(int seconds){
  _interval = seconds * 1000;
}

void PlantMonitor::run(){
  _currentTime = millis();
  if (_currentTime - _lastMonitored >= _interval){
    Serial.println("Time to monitor the plants!");
    if(_numPlants > 0){
      for(int i=0;i<_numPlants;i++){
        plants[i].sample();
        if(_mqttEnabled){
          if(plants[i].soilMoistureContent != -1){
            const char val = plants[i].soilMoistureContent;
            std::string url = "dev/PlantMonitor/" + plants[i].name + "soil_moisture"; 
            _mqtt.publish(url.c_str(), &val);
          }
          if(plants[i].soilTemperature != -1.0){
            const char val = plants[i].soilTemperature;
            std::string url = "dev/PlantMonitor/" + plants[i].name + "soil_temperature"; 
            _mqtt.publish(url.c_str(), &val);
          }
          if(plants[i].LUX != -1){
            const char val = plants[i].LUX;
            std::string url = "dev/PlantMonitor/" + plants[i].name + "luminance"; 
            _mqtt.publish(url.c_str(), &val);
          }
        }
      }
    } else{
      Serial.println("You do not have any plants configured right now.");
    }
    _lastMonitored = millis();
  }
}