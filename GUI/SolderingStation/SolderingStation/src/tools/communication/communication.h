#pragma once

#include <string>
#include <vector>
#include <map>

typedef struct {
	std::vector<std::string> ports;
	std::map<std::string, bool> isOpen;
}COMMUNICATION_DATA;
