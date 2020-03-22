#include <iostream>
#include "Monitor.h"
#include <Arduino.h>
#include "MQTT.h"

PlantMonitor monitor("ESP32Raam");

void loop();

int main(){
    monitor.setInterval(2);
    monitor.createPlant("Harry");
    monitor.plants[0].addSoilMoistureSensor(34, 1300, 3500, 110);
    monitor.plants[0].addLightSensor(13, -1.40, 7.6, 10000.0, 3.3);
    monitor.plants[0].addSoilTemperatureSensor(4, 301.0, 3950.0, 10000.0);
    monitor.plants[0].addPump(14,80,5, true);
    monitor.enableMQTT("Space Station", "Password", "192.168.8.45");   
    
    loop();
}

void loop(){
    while(true){
        monitor.run();
        delay(10000);
    }
}