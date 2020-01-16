#include <iostream>
#include "Plant.h"


int main(){
    Plant plant1("Dumbcane");
    cout << "You created plant: " << plant1.name << endl;
    plant1.sample();
    plant1.addSoilMoistureSensor(18, 1330, 2800, 50);
    plant1.addLightSensor(19, -1.42, 7.1, 10000.0, 3.3);
    plant1.addSoilTemperatureSensor(18,298.0, 3950.0, 10000.0);
    plant1.addPump(2,0.5,10,false);
    plant1.changeName("Harry");
    plant1.sample();
    cout << "Plant need watering: " << plant1.needsWatering << endl;
}