#pragma once

#include <wx/wx.h>
#include "../../tools/tools.h"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    void OnExit(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);
    void OnControl(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);

    wxPlot* plot;
};

