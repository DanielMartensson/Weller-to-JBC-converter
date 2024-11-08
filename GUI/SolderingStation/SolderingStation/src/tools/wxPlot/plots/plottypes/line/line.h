#pragma once

#include <memory>
#include <vector>
#include <wx/wx.h>

class Line {
private:
	unsigned int plotWidth;
	unsigned int plotHeight;
public:
	// Constructor
	Line(unsigned int plotWidth, unsigned int plotHeight);

	// Draw
	bool drawLine(wxDC& dc, std::vector<std::vector<double>>& plotData);
};