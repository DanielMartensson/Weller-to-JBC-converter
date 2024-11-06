#pragma once

#include <string>
#include <vector>
#include "plots/plots.h"

class wxPlot {
private:
	// A plot that contains a type and a figure
	std::shared_ptr<Plots> plots;

public:
	// Constructor
	wxPlot(WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE, WXPLOT_FIGURE wxPlotFigure = WXPLOT_FIGURE_STANDARD, unsigned int plotWidth = 100, unsigned int plotHeight = 100);

	// Getters
	std::shared_ptr<Plots> getPlots() { return plots; }

	// Set the data that is going to plot - This will draw the complete plot
	void setPlotData(std::vector<std::vector<double>>& plotData);
};