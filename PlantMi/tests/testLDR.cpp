#include "../Sensors.h"
#include <iostream>

using namespace std; 

int main(){
    LightSensor ldr;
    ldr.setPin(13);
    ldr.configure(-1.42, 7.1, 10000.0, .3);
    cout << ldr.measure() << endl;
}