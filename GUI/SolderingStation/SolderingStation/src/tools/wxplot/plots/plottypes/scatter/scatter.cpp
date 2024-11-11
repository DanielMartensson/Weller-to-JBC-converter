
#include "scatter.h"
#include "../../plottools/plottools.h"

bool Scatter::draw(wxDC& dc) {
	// Get the size of the data
	const unsigned int dataSize = data.size();

	// We must have at least double(2). One for X-axis and one for Y-axis
	if (dataSize % 2 == 0) {
		// Create a line plot
		int colourIndex = 0;
		for (unsigned int i = 0; i < dataSize; i += 2) {
			// Get data
			std::vector<double> xData = data.at(i);
			std::vector<double> yData = data.at(i + 1);

			// Get length of them both
			const unsigned int xDataLength = xData.size();
			const unsigned int yDataLength = yData.size();

			// If they are not the same length - Return false
			if (xDataLength != yDataLength) {
				return false;
			}

			// Find max och min value
			double minX, maxX, minY, maxY;
			maxMinData(xData, minX, maxX);
			maxMinData(yData, minY, maxY);

			// Set line colour
			wxColour colour = colourIndex < plotColours.size() ? plotColours.at(colourIndex++) : plotColours.at(PLOT_COLOUR_BLACK);
			wxPen pen(colour);
			if (fillCircle) {
				dc.SetBrush(colour);
			}
			dc.SetPen(pen);

			// Compute scalars
			const double scalarX = (plotEndWidth - plotStartWidth) / (maxX - minX);
			const double scalarY = (plotEndHeight - plotStartHeight) / (maxY - minY);

			// Draw lines
			for (unsigned int j = 0; j < xDataLength; j++) {
				const wxCoord x = scalarX * xData.at(j) + plotStartWidth;
				const wxCoord y = -scalarY * yData.at(j) + plotEndHeight;
				dc.DrawCircle(x, y, radius);
			}
		}
	}

	return true;
}
