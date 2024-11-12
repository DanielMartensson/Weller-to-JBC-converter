#pragma once

#include <vector>

void maxMinData(const std::vector<double>& data, double& minLimit, double& maxLimit);
double linearScalarXaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);
double linearScalarYaxis(const double value, const double oldMinLimit, const double newMinLimit, const double oldMaxLimit, const double newMaxLimit);
bool check2DdataSize(const std::vector<std::vector<double>>& data);
void findMaxMin2Ddata(const std::vector<std::vector<double>>& data, double& minX, double& maxX, double& minY, double& maxY);