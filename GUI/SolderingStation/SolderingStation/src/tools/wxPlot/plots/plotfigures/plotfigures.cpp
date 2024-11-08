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

void PlotFigure::drawFigure(wxDC& dc) {
	switch (wxPlotFigure) {
	case WXPLOT_FIGURE_STANDARD:
		standard->drawFigure(dc);
		break;
	default:
		break;
	}
}