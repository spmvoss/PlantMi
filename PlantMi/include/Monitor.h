/*
  Monitor.h - Library for monitor class
  Can contain multiple plant classes and will handle the monitoring and reporting
  Created by Sander P.M. Voss, March 09, 2020.
  Released into the public domain.
*/

#ifndef MONITOR_H
#define MONITOR_H

#include "Plant.h"

class PlantMonitor{
    private:
        int _ID;
        int _numPlants;
        int _maxPlants;
        int _interval;
        unsigned long _lastMonitored;
        unsigned long _currentTime;
    public:
    PlantMonitor();
    Plant plants[4] = {{"None"},{"None"},{"None"},{"None"}};
    void setID(int id);
    void createPlant(string name);
    void setInterval(int seconds);
    void run();
};

#endif