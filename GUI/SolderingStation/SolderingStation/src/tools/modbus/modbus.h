#pragma once

bool createModbusClient();
bool readHoldingRegister(const char port[], uint16_t address, uint16_t quantity, uint16_t registers[]);