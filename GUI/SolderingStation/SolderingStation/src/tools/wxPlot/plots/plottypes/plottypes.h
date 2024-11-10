#pragma once

#include "line/line.h"
#include "scatter/scatter.h"
#include "../plottools/plottools.h"

class PlotTypes {

private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// Charts
	Line line;
	Scatter scatter;

public:
	// Constructor
	PlotTypes() { }

	// Getters
	Line& getLine() { return line; }
	Scatter& getScatter() { return scatter; }

	// Setters
	void setWxPlotType(WXPLOT_TYPE wxPlotType) { this->wxPlotType = wxPlotType; }
	void setRadius(const wxCoord radius);
	void fillCircles(const bool fillCircle);
	void setData(const std::vector<std::vector<double>>& data);
	void setPlotStartWidth(const wxCoord& plotStartWidth);
	void setPlotStartHeight(const wxCoord& plotStartHeight);
	void setPlotEndWidth(const wxCoord& plotEndWidth);
	void setPlotEndHeight(const wxCoord& plotEndHeight);

	// Functions
	void drawType(wxDC& dc);
};