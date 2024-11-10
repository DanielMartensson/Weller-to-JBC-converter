#include "plots.h"

void Plots::setWxPlotType(WXPLOT_TYPE wxPlotType) {
	plotTypes.setWxPlotType(wxPlotType);
	plotFigures.setWxPlotType(wxPlotType);
}