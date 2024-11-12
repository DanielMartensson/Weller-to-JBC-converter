#include "plotfigures.h"

void PlotFigure::drawFigure(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		standard.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		standard.drawFigure(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		standard.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		standard.drawFigure(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		standard.drawFigure(dc);
		break;
	default:
		break;
	}
}

void PlotFigure::drawTicks(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		standard.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		standard.drawTicks(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		standard.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		standard.drawTicks(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		standard.drawTicks(dc);
		break;
	default:
		break;
	}
}

void PlotFigure::drawGrid(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		standard.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		standard.drawGrid(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		standard.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		standard.drawGrid(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		standard.drawGrid(dc);
		break;
	default:
		break;
	}
}

void PlotFigure::drawLegend(wxDC& dc) {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		standard.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SCATTER:
		standard.drawLegend(dc);
		break;
	case WXPLOT_TYPE_LINE_SCATTER:
		standard.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SPLINE:
		standard.drawLegend(dc);
		break;
	case WXPLOT_TYPE_SPLINE_SCATTER:
		standard.drawLegend(dc);
		break;
	default:
		break;
	}
}

void PlotFigure::setTitle(const wxString& title) {
	standard.setTitle(title);
}

void PlotFigure::setXlabel(const wxString& xLabel) {
	standard.setXlabel(xLabel); 
}

void PlotFigure::setYlabel(const wxString& yLabel) {
	standard.setYlabel(yLabel); 
}

void PlotFigure::setTicks(const unsigned int ticks) {
	standard.setTicks(ticks);
}

void PlotFigure::gridOn(const bool useGrid) {
	standard.gridOn(useGrid);
}

void PlotFigure::setPlotStartWidth(const wxCoord plotStartWidth) {
	standard.setPlotStartWidth(plotStartWidth); 
}

void PlotFigure::setPlotStartHeight(const wxCoord plotStartHeight) {
	standard.setPlotStartHeight(plotStartHeight); 
}

void PlotFigure::setPlotEndWidth(const wxCoord plotEndWidth) {
	standard.setPlotEndWidth(plotEndWidth); 
}

void PlotFigure::setPlotEndHeight(const wxCoord plotEndHeight) {
	standard.setPlotEndHeight(plotEndHeight); 
}

void PlotFigure::setData(const std::vector<std::vector<double>>& data) {
	standard.setData(data);
}

wxCoord PlotFigure::getPlotStartWidth() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return standard.getPlotStartWidth();
	case WXPLOT_TYPE_SCATTER:
		return standard.getPlotStartWidth();
	case WXPLOT_TYPE_LINE_SCATTER:
		return standard.getPlotStartWidth();
	case WXPLOT_TYPE_SPLINE:
		return standard.getPlotStartWidth();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return standard.getPlotStartWidth();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotEndWidth() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return standard.getPlotEndWidth();
	case WXPLOT_TYPE_SCATTER:
		return standard.getPlotEndWidth();
	case WXPLOT_TYPE_LINE_SCATTER:
		return standard.getPlotEndWidth();
	case WXPLOT_TYPE_SPLINE:
		return standard.getPlotEndWidth();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return standard.getPlotEndWidth();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotStartHeight() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return standard.getPlotStartHeight();
	case WXPLOT_TYPE_SCATTER:
		return standard.getPlotStartHeight();
	case WXPLOT_TYPE_LINE_SCATTER:
		return standard.getPlotStartHeight();
	case WXPLOT_TYPE_SPLINE:
		return standard.getPlotStartHeight();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return standard.getPlotStartHeight();
	default:
		return 0;
		break;
	}
}

wxCoord PlotFigure::getPlotEndHeight() const {
	switch (wxPlotType) {
	case WXPLOT_TYPE_LINE:
		return standard.getPlotEndHeight();
	case WXPLOT_TYPE_SCATTER:
		return standard.getPlotEndHeight();
	case WXPLOT_TYPE_LINE_SCATTER:
		return standard.getPlotEndHeight();
	case WXPLOT_TYPE_SPLINE:
		return standard.getPlotEndHeight();
	case WXPLOT_TYPE_SPLINE_SCATTER:
		return standard.getPlotEndHeight();
	default:
		return 0;
		break;
	}
}