#pragma once

#include <wx/wx.h>


class ControlFrame : public wxFrame
{

private:

    wxButton* startButton;
    wxButton* stopButton;
    wxSlider* pwmSlider;

    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void EnableComponents(const bool enable);

public:
    ControlFrame();
};