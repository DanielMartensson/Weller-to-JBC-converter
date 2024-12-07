#pragma once

#include <string>
#include <vector>
#include <map>

typedef struct {
	std::vector<std::string> ports;
	std::map<std::string, bool> isOpen;
	bool isStarted;
}COMMUNICATION_DATA;

/* Analog inputs */
bool receiveAnalogInputs();
float readTemperatureRaw();
float readSetpointRaw();
float readCurrentRaw();
float readTemperature();
float readSetpoint();
float readCurrent();

/* Digital inputs */
bool receiveNSleep();

/* Digital outputs */
bool receiveLeakageActive();
bool receiveLedGreen();


