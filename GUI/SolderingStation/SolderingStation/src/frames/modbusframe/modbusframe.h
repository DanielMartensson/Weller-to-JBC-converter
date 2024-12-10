#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include "../../tools/tools.h"

class ModbusFrame : public wxFrame
{
protected:
    // Fields
    COMMUNICATION_DATA& communicationData;

    // Items
    wxComboBox* modbusPorts;
    wxTimer* timer;
    wxGrid* analogInputGrid;
    wxGrid* parameterGrid;


public:
    ModbusFrame(COMMUNICATION_DATA& communicationData);

    // Functions
    void OnClose(wxCloseEvent& event);
    void OnTimer(wxTimerEvent& event);
    wxGrid* CreateAnalogInputGrid(wxPanel* panel, const unsigned int rows);
    wxGrid* CreateAnalogInputCalibrationGrid(wxPanel* panel, const unsigned int rows, const unsigned int maxADC);
    void SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const float value);
    void SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const char value[]);
    float GetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column);
};