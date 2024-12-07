#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include "../../tools/tools.h"

class ModbusFrame : public wxFrame
{
private:
    // Fields
    COMMUNICATION_DATA& communicationData;

    // Items
    wxComboBox* modbusPorts;
    wxTimer* timer;
    wxGrid* analogInputGrid;
    wxGrid* parameterGrid;

   

    // Events
    void OnClose(wxCloseEvent& event);
    void OnTimer(wxTimerEvent& event);

public:
    ModbusFrame(COMMUNICATION_DATA& communicationData);

};