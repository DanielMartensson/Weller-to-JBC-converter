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
	void setTicks(const unsigned int gridSize);
	void gridOn(const bool grid);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);
	void setData(const std::vector<std::vector<double>>& data);

	// Getters
	wxCoord getPlotStartWidth() const;
	wxCoord getPlotEndWidth() const;
	wxCoord getPlotStartHeight() const;
	wxCoord getPlotEndHeight() const;

	// Functions
	void drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawTicks(wxDC& dc);
	void drawLegend(wxDC& dc);
};