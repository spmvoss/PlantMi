/*
  Arduino.cpp - Dummy library file for Arduino development
  Created by Sander P.M. Voss, November 25, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include <iostream>

SerialObj Serial;

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
        case 18 : return 2000;
        case 19: return 3000;
        default : return 10;
    }
}

bool digitalRead(int pin){
    if(pin%2 == 0){
        return true;
    } else{
        return false;
    }
}

void digitalWrite(int pin, bool mode){}

void delay(int time){}

SerialObj::SerialObj(){
    // Nada
}

void SerialObj::println(std::string msg){
    std::cout << msg << std::endl;
}

void SerialObj::println(int num){
    std::cout << num << std::endl;
}

void SerialObj::println(double num){
    std::cout << num << std::endl;
}

void SerialObj::print(std::string msg){
    std::cout << msg;
}

void SerialObj::print(int num){
    std::cout << num;
}

void SerialObj::print(double num){
    std::cout << num;
}