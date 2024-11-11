#include "functions.h"

void maxMinData(std::vector<double>& data, double& minLimit, double& maxLimit) {
	minLimit = data.at(0);
	maxLimit = data.at(0);
	const unsigned int dataLength = data.size();
	for (unsigned int i = 1; i < dataLength; i++) {
		if (data.at(i) < minLimit) {
			minLimit = data.at(i);
		}
		if (data.at(i) > maxLimit) {
			maxLimit = data.at(i);
		}
	}
}