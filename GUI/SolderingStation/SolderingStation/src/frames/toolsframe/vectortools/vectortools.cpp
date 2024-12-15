#include "vectortools.h"

void VectorTools::addNewValue(std::vector<double>& list, const double value, const size_t maxLength) {
	const size_t length = list.size();
	if (length > maxLength) {
		list.erase(list.begin(), list.begin() + length - maxLength);
	}
	list.push_back(value);
}