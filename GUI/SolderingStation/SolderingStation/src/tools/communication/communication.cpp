#include "communication.h"
#include "../tools.h"

static uint16_t analogInputs[9];

bool receiveAnalogInputs() {
    return modbus_client_get_analog_inputs(analogInputs, 0, 9);
}

float readTemperatureRaw() {
    return static_cast<float>(analogInputs[0]);
}

float readSetpointRaw() {
    return static_cast<float>(analogInputs[1]);
}

float readCurrentRaw() {
    return static_cast<float>(analogInputs[2]);
}

float readTemperature() {
    return uint16_to_float(analogInputs[3], analogInputs[4]);
}

float readSetpoint() {
    return uint16_to_float(analogInputs[5], analogInputs[6]);
}

float readCurrent() {
    return uint16_to_float(analogInputs[7], analogInputs[8]);
}

bool receiveNSleep() {
    uint8_t nSleep;
    modbus_client_get_digital_inputs(&nSleep, 0, 1);
    return nSleep & 0x1;
}

bool receiveLeakageActive() {
    uint8_t leakageActive;
    modbus_client_get_digital_outputs(&leakageActive, 0, 1);
    return (leakageActive >> 0) & 0x1;
}

bool receiveLedGreen() {
    uint8_t ledGreen;
    modbus_client_get_digital_outputs(&ledGreen, 0, 1);
    return (ledGreen >> 1) & 0x1;
}

