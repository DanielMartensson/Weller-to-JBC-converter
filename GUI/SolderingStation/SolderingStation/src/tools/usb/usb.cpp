
#include "usb.h"
#include <boost/asio.hpp>
#include <map>
#include <iostream>

// Enums
typedef enum {
	USB_FLOW_CONTROL_ENUM_NONE,
	USB_FLOW_CONTROL_ENUM_SOFTWARE,
	USB_FLOW_CONTROL_ENUM_HARDWARE
}USB_FLOW_CONTROL_ENUM;

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

static char temporaryPort[100] = { 0 };
static boost::asio::io_context io;
static std::map<std::string, std::shared_ptr<boost::asio::serial_port>> devicesUSB;

static bool USB_DeviceExist(const char port[]) {
	return devicesUSB.find(port) != devicesUSB.end() ? true : false;
}

static void checkPort(std::vector<std::string>& ports, const char port[]) {
	// Check if it already exist 
	if (USB_DeviceExist(port)) {
		if (devicesUSB.at(port)->is_open()) {
			ports.push_back(port);
		}
	}
	else {
		// Create temporary port
		boost::asio::serial_port addDevice(io);
		addDevice.open(port);
		if (addDevice.is_open()) {
			ports.push_back(port);
		}
		addDevice.close();
	}
}

static void tryPort(std::vector<std::string>& ports, const char portTemplate[]) {
	char port[MAX_PORT_LENGTH];
	for (int i = 0; i < 127; i++) {
		try {
			sprintf_s(port, "%s%i", portTemplate, i);
#if(defined(_GOOBYSOFT_DEBUG))
			std::printf("Reading port %s\n", port);
#endif
			checkPort(ports, port);
#if(defined(_GOOBYSOFT_DEBUG))
			std::printf("Port %s is available, collecting it\n", port);
#endif
		}
		catch (const boost::system::system_error& ex) {
			if (boost::asio::error::no_permission == ex.code().value() || boost::asio::error::access_denied == ex.code().value()) {
#if(defined(_GOOBYSOFT_DEBUG))
				std::printf("Port %s is bussy, collecting it\n", port);
#endif
				ports.push_back(port); // The port is bussy, it can be used.
			}
#if(defined(_GOOBYSOFT_DEBUG))
			else {
				std::printf("Port %s is not available. Error code: %i\n", port, ex.code().value());
			}
#endif
		}
	}
}

std::vector<std::string> USB_getAllPorts() {
	// Get the ports
	std::vector<std::string> ports;
	tryPort(ports, "COM");
	tryPort(ports, "/dev/ttyACM");
	tryPort(ports, "/dev/ttyUSB");
#if(defined(_GOOBYSOFT_DEBUG))
	std::printf("Total ports found: %i\n", (int)ports.size());
	for (size_t i = 0; i < ports.size(); i++) {
		std::printf("Port: %s\n", ports.at(i).c_str());
	}
#endif
	return ports;
}

bool USB_closeConnection(const char port[]) {
	if (USB_isConnected(port)) {
		devicesUSB.at(port)->close();
		devicesUSB.erase(port);
		return true;
	}
	else {
		if (USB_DeviceExist(port)) {
			devicesUSB.erase(port);
		}
		return false;
	}
}

unsigned int USB_getBaudRate(const char port[]) {
	boost::asio::serial_port::baud_rate getValue;
	devicesUSB[port]->get_option(getValue);
	return getValue.value();
}

unsigned int USB_getDataBit(const char port[]) {
	boost::asio::serial_port::character_size getValue;
	devicesUSB[port]->get_option(getValue);
	return getValue.value();
}

unsigned int USB_getFlowControl(const char port[]) {
	boost::asio::serial_port::flow_control getValue;
	devicesUSB[port]->get_option(getValue);
	return getValue.value();
}

unsigned int USB_getStopBit(const char port[]) {
	boost::asio::serial_port::stop_bits getValue;
	devicesUSB[port]->get_option(getValue);
	return getValue.value();
}

unsigned int USB_getParity(const char port[]) {
	boost::asio::serial_port::parity getValue;
	devicesUSB[port]->get_option(getValue);
	return getValue.value();
}

bool USB_openConnection(const char port[], const unsigned int baudRate, const unsigned int dataBit, const unsigned int flowControl, const unsigned int stopBit, const unsigned int parity) {
	try {
		// Open connection
		std::shared_ptr<boost::asio::serial_port> addDevice = std::make_shared<boost::asio::serial_port>(io, port);
	
		// Baudrate options
		addDevice->set_option(boost::asio::serial_port::baud_rate(boost::asio::serial_port_base::baud_rate(baudRate)));

		// Data bits options
		addDevice->set_option(boost::asio::serial_port::character_size(boost::asio::serial_port_base::character_size(dataBit)));

		// Control flow options
		boost::asio::serial_port::flow_control controlFlowNone(boost::asio::serial_port_base::flow_control::none);
		boost::asio::serial_port::flow_control controlFlowSoftware(boost::asio::serial_port_base::flow_control::software);
		boost::asio::serial_port::flow_control controlFlowHardware(boost::asio::serial_port_base::flow_control::hardware);
		switch (flowControl) {
		case USB_FLOW_CONTROL_ENUM_NONE:
			addDevice->set_option(controlFlowNone);
			break;
		case USB_FLOW_CONTROL_ENUM_SOFTWARE:
			addDevice->set_option(controlFlowSoftware);
			break;
		case USB_FLOW_CONTROL_ENUM_HARDWARE:
			addDevice->set_option(controlFlowHardware);
			break;
		default:
			addDevice->set_option(controlFlowNone);
			break;
		}

		// Stop bits options
		boost::asio::serial_port_base::stop_bits stop_bits_one(boost::asio::serial_port_base::stop_bits::one);
		boost::asio::serial_port_base::stop_bits stop_bits_onepointfive(boost::asio::serial_port_base::stop_bits::onepointfive);
		boost::asio::serial_port_base::stop_bits stop_bits_two(boost::asio::serial_port_base::stop_bits::two);
		switch (stopBit) {
		case USB_STOP_BITS_ENUM_ONE:
			addDevice->set_option(stop_bits_one);
			break;
		case USB_STOP_BITS_ENUM_TWO:
			addDevice->set_option(stop_bits_two);
			break;
		default:
			addDevice->set_option(stop_bits_one);
			break;
		}

		// Parity options
		boost::asio::serial_port_base::parity parity_none(boost::asio::serial_port_base::parity::none);
		boost::asio::serial_port_base::parity parity_odd(boost::asio::serial_port_base::parity::odd);
		boost::asio::serial_port_base::parity parity_even(boost::asio::serial_port_base::parity::even);
		switch (parity) {
		case USB_PARITY_ENUM_NONE:
			addDevice->set_option(parity_none);
			break;
		case USB_PARITY_ENUM_ODD:
			addDevice->set_option(parity_odd);
			break;
		case USB_PARITY_ENUM_EVEN:
			addDevice->set_option(parity_even);
			break;
		default:
			addDevice->set_option(parity_none);
			break;
		}

		// Store the addDevice
		devicesUSB[port] = addDevice;
		return USB_isConnected(port);
	}
	catch (...) {
		return false;
	}
}

bool USB_isConnected(const char port[]) {
	bool isOpen = false;
	if (USB_DeviceExist(port)) {
		isOpen = devicesUSB.at(port)->is_open();
	}
	return isOpen;
}

std::vector<std::string> USB_getConnectedPorts() {
	std::vector<std::string> ports;
	size_t maxDevicesCDC = devicesUSB.size();
	for (auto const& [port, devices] : devicesUSB) {
		ports.push_back(port);
	}
	return ports;
}

std::vector<std::string> USB_getUnconnectedPorts() {
	std::vector<std::string> allPorts = USB_getAllPorts();
	std::vector<std::string> connectedPorts = USB_getConnectedPorts();
	std::vector<std::string> unconnectedPorts;
	for (const auto& port : allPorts) {
		// Check if it not exist
		if (std::find(connectedPorts.begin(), connectedPorts.end(), port) == connectedPorts.end()) {
			unconnectedPorts.push_back(port);
		}
	}
	return unconnectedPorts;
}


int32_t USB_writeProcess(const char port[], const uint8_t data[], const uint16_t size, const int32_t timeout_ms) {
	int32_t writtenBytes = 0;
	if (USB_DeviceExist(port)) {

		// Get the USB
		auto deviceUSB = devicesUSB.at(port);

		// Skapa en io_context och deadline_timer
		boost::asio::io_context io;
		boost::asio::deadline_timer timer(io);
		boost::system::error_code ec;

		// Starta deadline timer
		timer.expires_from_now(boost::posix_time::milliseconds(timeout_ms));
		timer.async_wait([&](const boost::system::error_code& error) {
			if (!error) {
				// Om timeout intr�ffar, st�ng seriellporten
				ec = boost::asio::error::operation_aborted;
				deviceUSB->cancel();
			}
			});

		// Starta en separat tr�d f�r att k�ra io_context
		std::thread io_thread([&]() { io.run(); });

		// Utf�r skrivoperationen
		writtenBytes = boost::asio::write(*deviceUSB, boost::asio::buffer(data, size), ec);

		// Avbryt timern och v�nta p� io_context-tr�den
		timer.cancel();
		if (io_thread.joinable()) {
			io_thread.join();
		}

		// Kontrollera fel
		if (ec) {
			if (ec == boost::asio::error::operation_aborted) {
				std::cerr << "Timeout intr�ffade under skrivning till port: " << port << std::endl;
				return -1; // Returnera felkod f�r timeout
			}
			std::cerr << "Fel vid skrivning: " << ec.message() << std::endl;
			return -1;
		}
	}
	return writtenBytes;
}


int32_t USB_readProcess(const char port[], uint8_t data[], const uint16_t size, const int32_t timeout_ms) {
	int32_t bytesRead = 0;
	if (USB_DeviceExist(port)) {

		// Get the USB
		auto deviceUSB = devicesUSB.at(port);

		// Skapa en io_context och deadline_timer
		boost::asio::io_context io;
		boost::asio::deadline_timer timer(io);
		boost::system::error_code ec;

		// Starta deadline timer
		timer.expires_from_now(boost::posix_time::milliseconds(timeout_ms));
		timer.async_wait([&](const boost::system::error_code& error) {
			if (!error) {
				// Om timeout intr�ffar, st�ng seriellporten
				ec = boost::asio::error::operation_aborted;
				deviceUSB->cancel();
			}
			});

		// Starta en separat tr�d f�r att k�ra io_context
		std::thread io_thread([&]() { io.run(); });

		// Utf�r l�soperationen
		bytesRead = boost::asio::read(*deviceUSB, boost::asio::buffer(data, size), ec);

		// Avbryt timern och v�nta p� io_context-tr�den
		timer.cancel();
		if (io_thread.joinable()) {
			io_thread.join();
		}

		// Kontrollera fel
		if (ec) {
			if (ec == boost::asio::error::operation_aborted) {
				std::cerr << "Timeout intr�ffade under l�sning fr�n port: " << port << std::endl;
				return -1; // Returnera felkod f�r timeout
			}
			std::cerr << "Fel vid l�sning: " << ec.message() << std::endl;
			return -1;
		}
	}

	return bytesRead;
}

void USB_setTemporaryPort(const char port[]) {
	strcpy_s(temporaryPort, port);
}

const char* USB_getTemporaryPort() {
	return temporaryPort;
}