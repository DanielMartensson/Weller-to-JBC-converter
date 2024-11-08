#pragma once

#include <string>
#include <vector>
#include "plots/plots.h"

class wxPlot : public wxPanel {
private:
	// A plot that contains a type and a figure
	std::shared_ptr<Plots> plots;

	// Data for the plot
	std::vector<std::vector<double>> plotData;

public:
	wxPlot(wxFrame* parent);

	// Constructor
	wxPlot(wxFrame* parent, WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE, WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_STANDARD, unsigned int plotWidth = 100, unsigned int plotHeight = 100);

	// Getters
	std::shared_ptr<Plots> getPlots() { return plots; }

	// Set the data that is going to plot - This will draw the complete plot
	void setPlotData(std::vector<std::vector<double>>& plotData);

	// This function renders the complete plot when the refresh function is called
	void OnPaint(wxPaintEvent& event);
};
