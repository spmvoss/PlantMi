/*
  Arduino.cpp - A test to validate the library
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "../Sensors.h"
#include <iostream>
#include "../Arduino.h"

using namespace std; 

int main(){
    cout << digitalRead(2) << endl;
    cout << digitalRead(3) << endl;
}