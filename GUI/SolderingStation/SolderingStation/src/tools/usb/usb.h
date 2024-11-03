#pragma once

#include <string>
#include <vector>

bool USB_closeConnection(const char port[]);
unsigned int USB_getBaudRate(const char port[]);
unsigned int USB_getDataBit(const char port[]);
unsigned int USB_getFlowControl(const char port[]);
unsigned int USB_getFlowControl(const char port[]);
unsigned int USB_getStopBit(const char port[]);
unsigned int USB_getParity(const char port[]);
bool USB_openConnection(const char port[], const unsigned int baudRate, const unsigned int dataBit, const unsigned int flowControl, const unsigned int stopBit, const unsigned int parity);
std::vector<std::string> USB_getAllPorts();
bool USB_isConnected(const char port[]);
std::vector<std::string> USB_getConnectedPorts();
std::vector<std::string> USB_getUnconnectedPorts();
std::vector<uint8_t> USB_startTransceiveProcesss(const char port[], const long long timeoutMilliseconds, uint8_t dataTX[], size_t size, std::string endingOfDataRX = "\r\n");
