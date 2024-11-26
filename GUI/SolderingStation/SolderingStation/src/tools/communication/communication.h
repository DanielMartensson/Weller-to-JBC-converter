#pragma once

typedef struct {
	float temperature;
	float current;
	float setpoint;
	char port[20];
	bool isOpen;
	bool isStarted;
}COMMUNICATION_DATA;

float receiveTemperature(const char port[]);
float receiveCurrent(const char port[]);
float receiveSetpoint(const char port[]);
