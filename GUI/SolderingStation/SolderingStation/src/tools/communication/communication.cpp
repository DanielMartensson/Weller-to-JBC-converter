#include "communication.h"
#include "../tools.h"

#define TEMPERATURE_ADDRESS 0
#define CURRENT_ADDRESS 2
#define POTENTIOMETER_ADDRESS 4

float uint16ToFloat(uint16_t high, uint16_t low) {
    union {
        uint32_t i;
        float f;
    } data;
    data.i = (static_cast<uint32_t>(high) << 16) | low;
    return data.f;
}

float receiveTemperature(const char port[]) {
	uint16_t registers[2];
	readInputRegisters(port, TEMPERATURE_ADDRESS, 2, registers);
    return uint16ToFloat(registers[1], registers[0]);
}

float receiveCurrent(const char port[]) {
	uint16_t registers[2];
	readInputRegisters(port, CURRENT_ADDRESS, 2, registers);
    return uint16ToFloat(registers[1], registers[0]);
}

float receiveSetpoint(const char port[]) {
    uint16_t registers[2];
    readInputRegisters(port, POTENTIOMETER_ADDRESS, 2, registers);
    return uint16ToFloat(registers[1], registers[0]);
}