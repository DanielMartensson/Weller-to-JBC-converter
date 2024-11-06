#pragma once

#include "plotfigures/plotfigures.h"
#include "plottypes/plottypes.h"

class Plots {

private:
	// Plot types are the type of the plot e.g line, bar, histogram, bubble, scatter etc.
	std::shared_ptr<PlotTypes> plotTypes;

	// Plot frames are figures of the frame e.g standard, 3D, custom etc.
	std::shared_ptr<PlotFigure> plotFigures;

public:
	// Constructor
	Plots(WXPLOT_TYPE wxPlotType, WXPLOT_FIGURE wxPlotFigure, unsigned int plotWidth, unsigned int plotHeight);

	// Getters
	std::shared_ptr<PlotTypes> getPlotTypes() { return plotTypes; }
	std::shared_ptr<PlotFigure> getPlotFigures() { return plotFigures; }

};