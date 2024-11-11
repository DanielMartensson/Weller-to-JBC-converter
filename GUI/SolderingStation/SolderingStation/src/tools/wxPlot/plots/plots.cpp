#include "plots.h"

void Plots::setWxPlotType(WXPLOT_TYPE wxPlotType) {
	plotTypes.setWxPlotType(wxPlotType);
	plotFigures.setWxPlotType(wxPlotType);
}
void Plots::setData(const std::vector<std::vector<double>>& data) {
	plotTypes.setData(data);
	plotFigures.setData(data);
}