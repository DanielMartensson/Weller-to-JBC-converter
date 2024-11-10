#pragma once

#include "standard/standard.h"
#include "../plottools/plottools.h"

class PlotFigure {
private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// Standard figure
	Standard standard;

public:
	// Constructor
	PlotFigure() {}

	// Getters
	Standard& getStandard() { return standard; }

	// Setters
	void setWxPlotType(WXPLOT_TYPE wxPlotType) { this->wxPlotType = wxPlotType; }
	void setTitle(const wxString& title);
	void setXlabel(const wxString& xLabel);
	void setYlabel(const wxString& yLabel);
	void setGridSize(const unsigned int gridSize);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);

	// Getters
	wxCoord getPlotStartWidth() const;
	wxCoord getPlotEndWidth() const;
	wxCoord getPlotStartHeight() const;
	wxCoord getPlotEndHeight() const;

	// Functions
	void drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawLegend(wxDC& dc);
};