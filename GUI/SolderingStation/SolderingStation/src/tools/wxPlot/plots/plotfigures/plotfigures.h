#pragma once

#include "standard/standard.h"

// Place plot figure enumeration here
typedef enum {
	WXPLOT_FIGURE_STANDARD,
}WXPLOT_FIGURE;

class PlotFigure {
private:
	// Figure select
	WXPLOT_FIGURE wxPlotFigure;

	// Standard figure
	std::shared_ptr<Standard> standard;

public:
	// Constructor
	PlotFigure(WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight);

	// Getters
	std::shared_ptr<Standard> getStandard() { return standard; }

	// Functions
	void drawFigure(wxDC& dc);
};