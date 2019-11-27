/*
  Arduino.cpp - Dummy library file for Arduino development
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "Arduino.h"

void pinMode(int pin, bool mode){
    // Nothing to do here
}

int analogRead(int pin){
    switch(pin){
        case 10 : return 100;
        case 11 : return 300;
        case 12 : return 600;
        case 13 : return 900;
        case 14 : return 1010;
        default : return 10;
    }
}