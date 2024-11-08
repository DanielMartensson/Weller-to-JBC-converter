#include "standard.h"

Standard::Standard(wxCoord plotWidth, wxCoord plotHeight) {
	this->plotWidth = plotWidth;
	this->plotHeight = plotHeight;
}


bool Standard::drawFigure(wxDC& dc) {
	// Draw rectangle
	const wxCoord x = 5;
	const wxCoord y = 5;
	dc.DrawRectangle(x, y, plotWidth, plotHeight);

	return true;
}
