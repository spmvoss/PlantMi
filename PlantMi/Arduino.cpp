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
    return 12*pin; // Just an arbritraty return value 
}