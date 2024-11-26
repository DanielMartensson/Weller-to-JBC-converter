#pragma once

#include <wx/wx.h>
#include "../../tools/tools.h"

class MainFrame : public wxFrame
{
private:
    // Fields
    COMMUNICATION_DATA communicationData;

    // Items
    wxPlot* plot; 

    // Functions
    void OnExit(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);
    void OnControl(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnSize(wxSizeEvent& event);

public:
    MainFrame();
};

