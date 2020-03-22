/*
  MQTT.cpp - Dummy library file for Arduino development
  Simulates functions needed for mqtt publishing
  Created by Sander P.M. Voss, March 19, 2020.
  Released into the public domain.
*/

#include "MQTT.h"
#include <iostream>

MQTT::MQTT(const char* name){
	_clientName = name;
}

void MQTT::connect(const char* ssid, const char* password, const char* host){std::cout << "Connected MQTT" << std::endl;}

void MQTT::publish(const char* url, const char* msg){std::cout << "Published!" << std::endl;}