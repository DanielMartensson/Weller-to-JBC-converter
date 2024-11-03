#pragma once

#include <wx/wx.h>

class ConnectFrame : public wxFrame
{
public:
    ConnectFrame();

private:
    void OpenConnection(wxCommandEvent& event);
    void CloseConnection(wxCommandEvent& event);
};