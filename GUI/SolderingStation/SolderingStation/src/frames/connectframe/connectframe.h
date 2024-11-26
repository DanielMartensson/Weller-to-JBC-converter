#pragma once

#include <wx/wx.h>
#include "../../tools/tools.h"

class ConnectFrame : public wxFrame
{
private:
    // Fields
    COMMUNICATION_DATA& communicationData;

    // Items
    wxListBox* unconnectedPortsList;
    wxListBox* connectedPortsList;
    wxComboBox* baudRateList;
    wxComboBox* databitList;
    wxComboBox* flowControlList;
    wxComboBox* stopBitList;
    wxComboBox* parityList;
    wxButton* scanPorts;
    wxButton* connectPort;
    wxButton* disconnectPort;

    // Functions
    void ScanPorts(wxCommandEvent& event);
    void OpenConnection(wxCommandEvent& event);
    void CloseConnection(wxCommandEvent& event);
    void SelectedUnconnectedPort(wxCommandEvent& event);
    void SelectedConnectedPort(wxCommandEvent& event);

public:
    ConnectFrame(COMMUNICATION_DATA& communicationData);
};