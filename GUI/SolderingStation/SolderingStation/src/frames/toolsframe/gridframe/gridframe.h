#pragma once

#include <wx/wx.h>
#include <wx/grid.h>

class GridFrame {
protected:
    wxGrid* CreateAnalogInputGrid(wxPanel* panel, const unsigned int rows);
    wxGrid* CreateAnalogInputCalibrationGrid(wxPanel* panel, const unsigned int rows, const unsigned int maxADC);
    wxGrid* CreateDigitalInputGrid(wxPanel* panel, const unsigned int rows);
    wxGrid* CreateDigitalOutputGrid(wxPanel* panel, const unsigned int rows);
    void SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const float value);
    void SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const char value[]);
    float GetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column);
};