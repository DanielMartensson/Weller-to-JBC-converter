#include "wxplot.h"

wxPlot::wxPlot(wxFrame* parent) : wxPanel(parent) {}

wxPlot::wxPlot(wxFrame* parent, WXPLOT_TYPE wxPlotType, WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight) : wxPanel(parent) {
	plots = std::make_shared<Plots>(wxPlotType, wxPlotFigure, plotWidth, plotHeight);

	// Important event handler that is going to update the complete plot
	Bind(wxEVT_PAINT, &wxPlot::OnPaint, this);
}

void wxPlot::setPlotData(std::vector<std::vector<double>>& plotData) {
	this->plotData = plotData;
}

void wxPlot::OnPaint(wxPaintEvent& event) {
	// Create DC
	wxPaintDC dc(this);

	// Draw type
	plots->getPlotTypes()->drawPlotType(dc, plotData);

	// Draw figure
	plots->getPlotFigures()->drawPlotFigure();
}

