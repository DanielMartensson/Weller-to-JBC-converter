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
bool Standard::drawFigure(wxDC& dc) {

	// Check the size
	if (!check2DdataSize(data)) {
		return false; // Missing an axis
	}


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
		yStartRectangle += 5; // Make a space
	}

	// Draw Y-label
	if (yLabel.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(yLabel, &textWidth, &textHeight);
		wxCoord x = 5;
		wxCoord y = plotEndHeight / 2 + textWidth / 2;
		xStartRectangle += textHeight + x;
		widthRectangle -= xStartRectangle * 2;
		dc.DrawRotatedText(yLabel, x + plotStartWidth / 2, y, 90);
	}
	else {
		xStartRectangle += 5;
		widthRectangle -= xStartRectangle * 2; // The right side
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
		heightRectangle -= 10; // Make a space
	}

	// Update the size
	plotStartHeight = yStartRectangle;
	plotStartWidth = xStartRectangle;
	plotEndHeight = heightRectangle + yStartRectangle;
	plotEndWidth = widthRectangle + xStartRectangle;

	// Draw rectangle frame
	dc.DrawRectangle(xStartRectangle, yStartRectangle, widthRectangle, heightRectangle);

	// Nothing went wrong
	return true;
}

/*
 * This function draw the ticks.
 * Call this function after you have drawn the plot type.
 */
void Standard::drawTicks(wxDC& dc) {
	if (ticks) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Set color - Black
		wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
		dc.SetPen(pen);

		// Compute the minimum and maximum value from the data for correct scaling
		double minX, maxX, minY, maxY;
		findMaxMin2Ddata(data, minX, maxX, minY, maxY);

		// Compute steps
		const unsigned int stepsX = (xStartRectangle + widthRectangle) / ticks;
		const unsigned int stepsY = (yStartRectangle + heightRectangle) / ticks;

		// Compute scalars
		const double scalarX = (maxX - minX) / ticks;
		const double scalarY = (minY - maxY) / ticks;

		// Counter
		double counter = 0;

		// Vertical lines
		wxCoord textWidth, textHeight;
		//std::string value = "1";
		char value[100] = "1";
		dc.GetTextExtent(value, &textWidth, &textHeight);
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += stepsX) {
			std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
			dc.DrawText(value, x + 5, yStartRectangle + heightRectangle - textHeight);
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle + widthRectangle - textWidth - 5, yStartRectangle + heightRectangle - textHeight);

		// Horizontal ticks
		counter = 0;
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += stepsY) {
			std::snprintf(value, sizeof(value), "%0.2f", maxY + scalarY * counter);
			dc.DrawText(value, xStartRectangle + 5, y);
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f /", maxY + scalarY * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle + 5, yStartRectangle + heightRectangle - textHeight*2);

	}
}

/*
 * This function draw the grid.
 * Call this function after you have drawn the plot type.
 */
void Standard::drawGrid(wxDC& dc) {
	if (useGrid) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Set color - Black
		wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
		dc.SetPen(pen);

		// Compute steps
		const unsigned int stepsX = (xStartRectangle + widthRectangle) / ticks;
		const unsigned int stepsY = (yStartRectangle + heightRectangle) / ticks;

		// Vertical lines
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += stepsX) {
			dc.DrawLine(x, yStartRectangle, x, yStartRectangle + heightRectangle);
		}

		// Horizontal lines
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += stepsY) {
			dc.DrawLine(xStartRectangle, y, xStartRectangle + widthRectangle, y);
		}
	}
}

/*
 * This function writes the legend
 */
void Standard::drawLegend(wxDC& dc) {

}