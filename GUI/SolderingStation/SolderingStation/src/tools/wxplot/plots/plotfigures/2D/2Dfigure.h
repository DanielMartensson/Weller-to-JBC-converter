#pragma once

#include "proportional/proportional.h"
#include "../../plottools/plottools.h"

class _2D_Figure {
private:
	// Type select
	WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE;

	// Proportional figure
	Proportional proportional;

public:
	// Constructor
	_2D_Figure() {}

	// Setters
	void setWxPlotType(const WXPLOT_TYPE wxPlotType);
	void setTitle(const wxString& title);
	void setXlabel(const wxString& xLabel);
	void setYlabel(const wxString& yLabel);
	void setTicks(const unsigned int gridSize);
	void gridOn(const bool grid);
	void setPlotStartWidth(const wxCoord plotStartWidth);
	void setPlotStartHeight(const wxCoord plotStartHeight);
	void setPlotEndWidth(const wxCoord plotEndWidth);
	void setPlotEndHeight(const wxCoord plotEndHeight);
	void setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition);
	void setData(const std::vector<std::vector<double>>& data);
	void legendOn(const bool useLegend);
	void setFontSize(const unsigned int fontSize);

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