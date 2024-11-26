#pragma once

#include <wx/wx.h>
#include "../../tools/tools.h"


class ControlFrame : public wxFrame
{

private:
    // Fields
    COMMUNICATION_DATA& communicationData;

    // Items
    wxButton* startButton;
    wxButton* stopButton;

    // Functions
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void EnableComponents(const bool enable);

public:
    ControlFrame(COMMUNICATION_DATA& communicationData);
};