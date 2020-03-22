/*
  MQTT.h - Dummy library file for Arduino development
  Simulates functions needed for mqtt publishing
  Created by Sander P.M. Voss, March 19, 2019.
  Released into the public domain.
*/
#ifndef MQTT_h
#define MQTT_h

class MQTT{
	private:
		const char* _clientName;
	public:
		MQTT(const char* name);
		void connect(const char* ssid, const char* password, const char* host);
		void publish(const char* url, const char* msg);
		void setName(const char* name);
};

#endif