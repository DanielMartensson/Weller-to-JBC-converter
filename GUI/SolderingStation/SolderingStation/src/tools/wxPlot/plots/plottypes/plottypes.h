#pragma once

#include "line/line.h"

// Place plot type enumeration here
typedef enum {
	WXPLOT_TYPE_LINE,
}WXPLOT_TYPE;

class PlotTypes {

private:
	// Type select
	WXPLOT_TYPE wxPlotType;

	// Line chart
	std::shared_ptr<Line> line;

public:
	// Constructor
	PlotTypes(WXPLOT_TYPE wxPlotType, unsigned int plotWidth, unsigned int plotHeight);

	// Getters
	std::shared_ptr<Line> getLine() { return line; }

	// Functions
	void drawPlotType(wxDC& dc, std::vector<std::vector<double>>& plotData);
};