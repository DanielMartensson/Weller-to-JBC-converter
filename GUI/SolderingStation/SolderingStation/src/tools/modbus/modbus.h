#pragma once
#include <cstdint>

bool createModbusClient();
bool readHoldingRegister(const char port[], uint16_t address, uint16_t quantity, uint16_t registers[]);
bool writeSingleRegister(const char port[], uint16_t address, uint16_t value);
bool writeMultipleRegisters(const char port[], uint16_t address, uint16_t quantity, const uint16_t registers[]);
bool readInputRegisters(const char port[], uint16_t address, uint16_t quantity, uint16_t registers[]);