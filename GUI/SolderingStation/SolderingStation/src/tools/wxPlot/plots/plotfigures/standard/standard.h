#pragma once

#include <string>
#include <vector>
#include <wx/wx.h>

class Standard {
protected:
	// General plot information
	wxCoord plotEndWidth = 0;
	wxCoord plotEndHeight = 0;
	wxCoord plotStartWidth = 0;
	wxCoord plotStartHeight = 0;
	unsigned int fontSize = 0;
	unsigned int gridSize = 0;
	wxString title;
	wxString xLabel;
	wxString yLabel;
	std::vector<wxString> legend;

public:
	// Constructor
	Standard() {}

	// Setters
	void setPlotStartWidth(const wxCoord plotStartWidth) { this->plotStartWidth = plotStartWidth; }
	void setPlotStartHeight(const wxCoord plotStartHeight) { this->plotStartHeight = plotStartHeight; }
	void setPlotEndWidth(const wxCoord plotEndWidth) { this->plotEndWidth = plotEndWidth; }
	void setPlotEndHeight(const wxCoord plotEndHeight) { this->plotEndHeight = plotEndHeight; }
	void setFontSize(const unsigned int fontSize) { this->fontSize = fontSize; }
	void setGridSize(const unsigned int gridSize) { this->gridSize = gridSize; }
	void setTitle(const wxString& title) { this->title = title; }
	void setXlabel(const wxString& xLabel) { this->xLabel = xLabel; }
	void setYlabel(const wxString& yLabel) { this->yLabel = yLabel; }
	void setLegend(const std::vector<wxString>& legend) { this->legend = legend; }

	// Getters
	wxCoord getPlotStartWidth() const { return plotStartWidth; }
	wxCoord getPlotStartHeight() const { return plotStartHeight; }
	wxCoord getPlotEndWidth() const { return plotEndWidth; }
	wxCoord getPlotEndHeight() const { return plotEndHeight; }

	// Functions
	void drawFigure(wxDC& dc);
	void drawGrid(wxDC& dc);
	void drawLegend(wxDC& dc);

};