#pragma once

#include <wx/wx.h>
#include "../../tools/wxplot/wxplot.h"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);

    wxPlot* plot;
};

