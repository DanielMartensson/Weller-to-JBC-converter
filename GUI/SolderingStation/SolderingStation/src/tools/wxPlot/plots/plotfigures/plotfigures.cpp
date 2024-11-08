#include "plotfigures.h"

PlotFigure::PlotFigure(WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight){
	// Remember the selection
	this->wxPlotFigure = wxPlotFigure;

	// Create figure
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_STANDARD:
		standard = std::make_shared<Standard>(plotWidth, plotHeight);
		break;
	default:
		break;
	}
}

void PlotFigure::drawPlotFigure() {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_STANDARD:
		break;
	default:
		break;
	}
}