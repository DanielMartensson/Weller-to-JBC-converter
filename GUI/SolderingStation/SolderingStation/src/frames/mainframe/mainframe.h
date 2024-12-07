#pragma once

#include <wx/wx.h>
#include "../../tools/tools.h"

class MainFrame : public wxFrame
{
private:
    // Fields
    COMMUNICATION_DATA communicationData;

    // The important 2D data for the plot
    std::vector<std::vector<double>> data2D;

    // Items
    wxPlot* plot; 

    // Events
    void OnExit(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);
    void OnControl(wxCommandEvent& event);
    void OnModbus(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnSize(wxSizeEvent& event);

public:
    MainFrame();
};

