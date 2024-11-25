#pragma once

#include <wx/wx.h>
#include "../../tools/wxplot/wxplot.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnConnect(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);

    wxPlot* plot;
};

