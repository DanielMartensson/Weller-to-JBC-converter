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


	// Compute the minimum and maximum value from the data for correct scaling
	double minX, maxX, minY, maxY;
	findMaxMin2Ddata(data, minX, maxX, minY, maxY);

	// Set default size on the rectangle
	wxCoord yStartRectangle = plotStartHeight;
	wxCoord xStartRectangle = plotStartWidth;
	wxCoord heightRectangle = plotEndHeight;
	wxCoord widthRectangle = plotEndWidth;

	// Set color - Black
	wxPen pen(plotColours.at(PLOT_COLOUR_BLACK));
	dc.SetPen(pen);

	// Prepare the rectangle so it can hold the ticks
	wxCoord ticksWidth = 0, ticksHeight = 0;
	if (ticks) {
		char value[100];
		std::snprintf(value, sizeof(value), "%0.2f", maxY);
		dc.GetTextExtent(value, &ticksWidth, &ticksHeight);
	}

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
		yStartRectangle += ticksHeight; // Make a space
	}

	// Draw Y-label on the right side
	if (yLabel.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(yLabel, &textWidth, &textHeight);
		wxCoord y = plotEndHeight / 2 + textWidth / 2;
		xStartRectangle += textHeight + 5;
		widthRectangle -= xStartRectangle + textHeight; // The right side
		dc.DrawRotatedText(yLabel, 5, y, 90);
	}
	else {
		xStartRectangle += 5;
		widthRectangle -= xStartRectangle + 5; // The right side
	}

	// Move the rectangle
	if (ticks) {
		xStartRectangle += ticksWidth + 5;
		widthRectangle -= xStartRectangle + (yLabel.length() > 0 ? -ticksHeight : -5); // The right side
	}

	// Draw X-label
	if (xLabel.length()) {
		wxCoord textWidth, textHeight;
		dc.GetTextExtent(xLabel, &textWidth, &textHeight);
		wxCoord x = plotEndWidth / 2 - textWidth / 2;
		heightRectangle -= yStartRectangle + ticksHeight * (title.length() > 0 ? 1 : 2) + 5;
		dc.DrawText(xLabel, x, heightRectangle + yStartRectangle + textHeight + 5);
	}
	else {
		heightRectangle -= ticksHeight * 2; // Make a space
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
		char value[100];
		for (wxCoord x = xStartRectangle; x <= xStartRectangle + widthRectangle; x += stepsX) {
			std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
			dc.GetTextExtent(value, &textWidth, &textHeight);
			dc.DrawText(value, x - textWidth / 2, yStartRectangle + heightRectangle + 5);
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f", maxX + scalarX * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle + widthRectangle - textWidth, yStartRectangle + heightRectangle + 5);

		// Horizontal ticks
		counter = 0;
		for (wxCoord y = yStartRectangle; y <= yStartRectangle + heightRectangle; y += stepsY) {
			std::snprintf(value, sizeof(value), "%0.2f", maxY + scalarY * counter);
			dc.GetTextExtent(value, &textWidth, &textHeight);
			dc.DrawText(value, xStartRectangle - textWidth - 5, y - textHeight + 5);
			counter++;
		}
		std::snprintf(value, sizeof(value), "%0.2f", maxY + scalarY * counter);
		dc.GetTextExtent(value, &textWidth, &textHeight);
		dc.DrawText(value, xStartRectangle - textWidth - 5, yStartRectangle + heightRectangle - textHeight + 5);

	}
}

/*
 * This function draw the grid.
 * Call this function after you have drawn the plot type.
 */
void Standard::drawGrid(wxDC& dc) {
	if (useGrid && ticks) {
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
	if (useLegend) {
		const wxCoord yStartRectangle = plotStartHeight;
		const wxCoord xStartRectangle = plotStartWidth;
		const wxCoord heightRectangle = plotEndHeight - plotStartHeight;
		const wxCoord widthRectangle = plotEndWidth - plotStartWidth;

		// Get the size of the legend
		const size_t legendSize = legend.size();

		// Get the largest text width
		wxCoord textWidth, textHeight;
		wxCoord largestTextWidth, largestTextHeight;
		for (size_t i = 0; i < legendSize; i++) {
			dc.GetTextExtent(legend.at(i), &textWidth, &textHeight);
			if (i == 0) {
				largestTextWidth = textWidth;
				largestTextHeight = textHeight;
			}
			else {
				if (textWidth > largestTextWidth) {
					largestTextWidth = textWidth;
				}
				if (textHeight > largestTextHeight) {
					largestTextHeight = textHeight;
				}
			}
		}

		// Draw a rectangle at...
		//switch()
		//dc.DrawRoundedRectangle()
	}
}