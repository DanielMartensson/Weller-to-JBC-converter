#include "standard.h"
#include "../../plottools/plottools.h"

/*
 * This function will do the following:
 * - Set the font
 * - Draw the title
 * - Draw the y-label
 * - Draw the x-label
 * - Draw the rectangle
 * - Update the rectangle size for correct plotting the plot type
 */
void Standard::drawFigure(wxDC& dc) {
	// Set the font, or get the font size
	if (fontSize) {
		dc.SetFont(wxFont(fontSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	}
	else {
		fontSize = dc.GetFont().GetPointSize();
	}

	// Set default size on the rectangle
	wxCoord yStartRectangle = plotStartHeight;
	wxCoord xStartRectangle = plotStartWidth;
	wxCoord heightRectangle = plotEndHeight;
	wxCoord widthRectangle = plotEndWidth;

	// Set color - Black
	wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
	dc.SetPen(pen);

	// Draw title
	if (title.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(title, &textWidth, &textHeight);
		wxCoord x = plotEndWidth / 2 - textWidth / 2;
		wxCoord y = 5;
		yStartRectangle += textHeight + y;
		heightRectangle -= yStartRectangle;
		dc.DrawText(title, x, y + plotStartHeight / 2);
	}
	else {
		yStartRectangle += 5;
	}

	// Compute the minimum and maximum value from the data

	// Draw Y-label
	if (yLabel.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(yLabel, &textWidth, &textHeight);
		wxCoord x = 5;
		wxCoord y = plotEndHeight / 2 + textWidth / 2;
		xStartRectangle += textHeight + x; //+ numberWidth;
		widthRectangle -= xStartRectangle * 2;
		dc.DrawRotatedText(yLabel, x + plotStartWidth / 2, y, 90);
	}
	else {
		xStartRectangle += 5;
		widthRectangle -= xStartRectangle * 2;
	}

	// Draw X-label
	if (xLabel.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(xLabel, &textWidth, &textHeight);
		wxCoord x = plotEndWidth / 2 - textWidth / 2;
		wxCoord y = plotEndHeight - textHeight;
		heightRectangle -= yStartRectangle;
		dc.DrawText(xLabel, x, heightRectangle + yStartRectangle);
	}
	else {
		heightRectangle -= 10;
	}

	// Update the size
	plotStartHeight = yStartRectangle;
	plotStartWidth = xStartRectangle;
	plotEndHeight = heightRectangle + yStartRectangle;
	plotEndWidth = widthRectangle + xStartRectangle;

	// Draw rectangle frame
	dc.DrawRectangle(xStartRectangle, yStartRectangle, widthRectangle, heightRectangle);
	
}

/*
 * This function draw the grid.
 * Call this function after you have drawn the plot type.
 */
void Standard::drawGrid(wxDC& dc) {
	wxCoord yStartRectangle = plotStartHeight;
	wxCoord xStartRectangle = plotStartWidth;
	wxCoord heightRectangle = plotEndHeight - plotStartHeight;
	wxCoord widthRectangle = plotEndWidth - plotStartWidth;

	// Set color - Black
	wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
	dc.SetPen(pen);

	if (gridSize) {
		// Vertical lines
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += gridSize) {
			dc.DrawLine(x, yStartRectangle, x, yStartRectangle + heightRectangle);
		}

		// Horizontal lines
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += gridSize) {
			dc.DrawLine(xStartRectangle, y, xStartRectangle + widthRectangle, y);
		}
	}
}

/*
 * This function writes the legend
 */
void Standard::drawLegend(wxDC& dc) {

}