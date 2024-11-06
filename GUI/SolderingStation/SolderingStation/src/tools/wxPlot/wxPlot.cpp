#include "wxPlot.h"

wxPlot::wxPlot(WXPLOT_TYPE wxPlotType, WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight) {
	plots = std::make_shared<Plots>(wxPlotType, wxPlotFigure, plotWidth, plotHeight);
}

void wxPlot::setPlotData(std::vector<std::vector<double>>& plotData) {
	// Draw type
	plots->getPlotTypes()->drawPlotType();

	// Draw figure
	plots->getPlotFigures()->drawPlotFigure(plotData);
}