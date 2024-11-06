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
void PlotTypes::drawPlotType() {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		break;
	default:
		break;
	}
}