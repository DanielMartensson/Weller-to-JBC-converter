#pragma once

#include <string>
#include <vector>
#include "plots/plots.h"

class wxPlot : public wxPanel {
private:
	// A plot that contains a type and a figure
	Plots plots;
public:
	// Constructor
	wxPlot(wxFrame* parent, WXPLOT_TYPE wxPlotType = WXPLOT_TYPE_LINE);

	// Getters
	Plots& getPlots() { return plots; }

	// Setters
	void setFontSize(const unsigned int fontSize) { plots.getPlotFigures().getStandard().setFontSize(fontSize); }
	void setTitle(const wxString title) { plots.getPlotFigures().setTitle(title); }
	void setXlabel(const wxString xLabel) { plots.getPlotFigures().setXlabel(xLabel); }
	void setYlabel(const wxString yLabel) { plots.getPlotFigures().setYlabel(yLabel); }
	void setGridSize(const unsigned int gridSize) { plots.getPlotFigures().setGridSize(gridSize); }
	void setPlotStartWidth(const wxCoord plotStartWidth) { plots.getPlotFigures().setPlotStartWidth(plotStartWidth); }
	void setPlotStartHeight(const wxCoord plotStartHeight) { plots.getPlotFigures().setPlotStartHeight(plotStartHeight); }
	void setPlotEndWidth(const wxCoord plotEndWidth) { plots.getPlotFigures().setPlotEndWidth(plotEndWidth); }
	void setPlotEndHeight(const wxCoord plotEndHeight) { plots.getPlotFigures().setPlotEndHeight(plotEndHeight); }
	void setData(const std::vector<std::vector<double>>& data) { plots.setData(data); }
	void setRadius(const wxCoord radius) { plots.getPlotTypes().setRadius(radius); }
	void fillCircles(const bool fillCircle) { plots.getPlotTypes().fillCircles(fillCircle); }

	// This function renders the complete plot when the refresh function is called
	void OnPaint(wxPaintEvent& event);
};
