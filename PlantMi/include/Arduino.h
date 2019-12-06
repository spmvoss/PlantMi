/*
  Arduino.h - Dummy library file for Arduino development
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/
#ifndef Arduino_h
#define Arduino_h

#define INPUT true // Used in setting the pinmode to input
#define OUTPUT true // Used in setting the pinmode to output
#define HIGH true // Used in digitalwrite
#define LOW true // Used in digialWrite

// function to mimick the setting of the pinmode
void pinMode(int pin, bool mode);

// function to mimick the reading of an analog pin
int analogRead(int pin);

bool digitalRead(int pin);

void digitalWrite(int pin, bool mode);

void delay(int time);

#endif