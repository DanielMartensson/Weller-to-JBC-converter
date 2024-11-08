#include "plottypes.h"

PlotTypes::PlotTypes(WXPLOT_TYPE wxPlotType, unsigned int plotWidth, unsigned int plotHeight) {
	// Remember the type
	this->wxPlotType = wxPlotType;

	// Create type
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		line = std::make_shared<Line>(plotWidth, plotHeight);
		break;
	default:
		break;
	}
}

// Functions
void PlotTypes::drawPlotType(wxDC& dc, std::vector<std::vector<double>>& plotData) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		line->drawPlotLine(dc, plotData);
		break;
	default:
		break;
	}
}