#pragma once

#include <string>
#include <vector>

// Enums
typedef enum {
	USB_CONTROL_FLOW_ENUM_NONE,
	USB_CONTROL_FLOW_ENUM_SOFTWARE,
	USB_CONTROL_FLOW_ENUM_HARDWARE
}USB_CONTROL_FLOW_ENUM;

typedef enum {
	USB_STOP_BITS_ENUM_ONE,
	USB_STOP_BITS_ENUM_TWO
}USB_STOP_BITS_ENUM;

typedef enum {
	USB_PARITY_ENUM_NONE,
	USB_PARITY_ENUM_ODD,
	USB_PARITY_ENUM_EVEN
}USB_PARITY_ENUM;

// Defines
#define MAX_PORT_LENGTH 20

bool USB_closeConnection(const char port[]);
bool USB_openConnection(const char port[], const unsigned int baudrate, const unsigned int dataBits, const unsigned int flowControl, const unsigned int stopBits, const unsigned int parity);
std::vector<std::string> USB_getAllPorts();
bool USB_isConnected(const char port[]);
std::vector<std::string> USB_getPortsOfConnectedDevices();
std::vector<uint8_t> USB_startTransceiveProcesss(const char port[], const long long timeoutMilliseconds, uint8_t dataTX[], size_t size, std::string endingOfDataRX = "\r\n");
