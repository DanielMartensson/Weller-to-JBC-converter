
#include "line.h"

Line::Line(unsigned int plotWidth, unsigned int plotHeight) {
	
}

bool Line::drawLine(wxDC& dc, std::vector<std::vector<double>>& plotData) {
	// Count the how many rows the data has
	const int rows = plotData.size();

	// Make sure that rows can be divided by 2, or else we are missing either X-axis or Y-axis
	if (rows % 2 != 0) {
		return false;
	}

	// Draw lines for each plot
	for (int i = 0; i < rows; i += 2) {
		// Get data
		std::vector<double> xData = plotData.at(i);
		std::vector<double> yData = plotData.at(i + 1);

		// Get length of each vector
		const int xLength = xData.size();
		const int yLength = yData.size();

		// If they are not the same lenght, return false as an error
		if (xLength != yLength) {
			return false;
		}

		// Draw the line
		dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); // black line, 3 pixels thick

		// Iterate each vector for making lines
		for (int j = 0; j < xLength; j += 2) {
			const wxCoord x1 = xData.at(j);
			const wxCoord y1 = yData.at(j);
			const wxCoord x2 = xData.at(j + 1);
			const wxCoord y2 = yData.at(j + 1);
			dc.DrawLine(x1, y1, x2, y2);
		}
	}

	return true;
}
