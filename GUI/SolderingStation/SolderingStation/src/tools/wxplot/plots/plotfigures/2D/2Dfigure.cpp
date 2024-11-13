#include "2Dfigure.h"

void _2D_Figure::setWxPlotType(const WXPLOT_TYPE wxPlotType) {
	this->wxPlotType = wxPlotType;
}

void _2D_Figure::setTitle(const wxString& title) {
	standard.setTitle(title);
}

void _2D_Figure::setXlabel(const wxString& xLabel) {
	standard.setXlabel(xLabel);
}

void _2D_Figure::setYlabel(const wxString& yLabel) {
	standard.setYlabel(yLabel);
}

void _2D_Figure::setTicks(const unsigned int ticks) {
	standard.setTicks(ticks);
}

void _2D_Figure::gridOn(const bool useGrid) {
	standard.gridOn(useGrid);
}

void _2D_Figure::setPlotStartWidth(const wxCoord plotStartWidth) {
	standard.setPlotStartWidth(plotStartWidth);
}

void _2D_Figure::setPlotStartHeight(const wxCoord plotStartHeight) {
	standard.setPlotStartHeight(plotStartHeight);
}

void _2D_Figure::setPlotEndWidth(const wxCoord plotEndWidth) {
	standard.setPlotEndWidth(plotEndWidth);
}

void _2D_Figure::setPlotEndHeight(const wxCoord plotEndHeight) {
	standard.setPlotEndHeight(plotEndHeight);
}

void _2D_Figure::setData(const std::vector<std::vector<double>>& data) {
	standard.setData(data);
}

void _2D_Figure::legendOn(const bool useLegend) {
	standard.legendOn(useLegend);
}

void _2D_Figure::setLegend(const std::vector<wxString>& legend, const PLACEMENT legendPosition) {
	standard.setLegend(legend, legendPosition);
}

void _2D_Figure::setFontSize(const unsigned int fontSize) {
	standard.setFontSize(fontSize);
}

wxCoord _2D_Figure::getPlotStartWidth() const {
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

wxCoord _2D_Figure::getPlotEndWidth() const {
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

wxCoord _2D_Figure::getPlotStartHeight() const {
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

wxCoord _2D_Figure::getPlotEndHeight() const {
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

void _2D_Figure::drawFigure(wxDC& dc) {
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
		standard.drawFigure(dc);
		break;
	}
}

void _2D_Figure::drawTicks(wxDC& dc) {
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
		standard.drawTicks(dc);
		break;
	}
}

void _2D_Figure::drawGrid(wxDC& dc) {
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
		standard.drawGrid(dc);
		break;
	}
}

void _2D_Figure::drawLegend(wxDC& dc) {
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
		standard.drawLegend(dc);
		break;
	}
}