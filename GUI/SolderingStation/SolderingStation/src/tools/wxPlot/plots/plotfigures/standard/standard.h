#pragma once

#include <string>
#include <vector>
#include <memory>
#include <wx/wx.h>

class Standard {
private:
	// General plot information
	unsigned int plotWidth;
	unsigned int plotHeight;
	unsigned int fontSize;
	std::string title;
	std::string xLabel;
	std::string yLabel;
	std::vector<std::string> legend;

	// General flags
	bool gridOn = false;
	bool legendOn = false;
	bool xLabelOn = false;
	bool yLabelOn = false;
	bool titleOn = false;

public:
	// Constructor
	Standard(unsigned int plotWidth, unsigned int plotHeight);

	// General setters
	void setPlotWidth(unsigned int plotWidth) { this->plotWidth = plotWidth; }
	void setPlotHeight(unsigned int plotHeight) { this->plotHeight = plotHeight; }
	void setFontSize(unsigned int fontSize) { this->fontSize = fontSize; }
	void setGridOn(bool gridOn) { this->gridOn = gridOn; }
	void setLegendOn(bool legendOn) { this->legendOn = legendOn; }
	void setXLabelOn(bool xLabelOn) { this->xLabelOn = xLabelOn; }
	void setYLabelOn(bool yLabelOn) { this->yLabelOn = yLabelOn; }
	void setTitleOn(bool titleOn) { this->titleOn = titleOn; }
	void setTitle(std::string& title) { this->title = title; }
	void setXlabel(std::string& xLabel) { this->xLabel = xLabel; }
	void setYlabel(std::string& yLabel) { this->yLabel = yLabel; }
	void setLegend(std::vector<std::string>& legend) { this->legend = legend; }
};