#include "plots.h"

Plots::Plots(WXPLOT_TYPE wxPlotType, WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight) {
	plotTypes = std::make_shared<PlotTypes>(wxPlotType, plotWidth, plotHeight);
	plotFigures = std::make_shared<PlotFigure>(wxPlotFigure, plotWidth, plotHeight);
}