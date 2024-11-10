#include "plottypes.h"

// Functions
void PlotTypes::drawType(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		line.draw(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		scatter.draw(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		line.draw(dc);
		scatter.draw(dc);
		break;
	default:
		break;
	}
}

void PlotTypes::setRadius(const wxCoord radius) {
	scatter.setRadius(radius);
}

void PlotTypes::fillCircles(const bool fillCircle) {
	scatter.fillCircles(fillCircle);
}

void PlotTypes::setData(const std::vector<std::vector<double>>& data) {
	line.setData(data);
	scatter.setData(data);
}

void PlotTypes::setPlotStartWidth(const wxCoord& plotStartWidth) {
	line.setPlotStartWidth(plotStartWidth);
	scatter.setPlotStartWidth(plotStartWidth);
}

void PlotTypes::setPlotStartHeight(const wxCoord& plotStartHeight) {
	line.setPlotStartHeight(plotStartHeight);
	scatter.setPlotStartHeight(plotStartHeight);
}

void PlotTypes::setPlotEndWidth(const wxCoord& plotEndWidth) {
	line.setPlotEndWidth(plotEndWidth);
	scatter.setPlotEndWidth(plotEndWidth);
}

void PlotTypes::setPlotEndHeight(const wxCoord& plotEndHeight) {
	line.setPlotEndHeight(plotEndHeight);
	scatter.setPlotEndHeight(plotEndHeight);
}
