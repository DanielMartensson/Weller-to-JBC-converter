
#include "connectframe.h"
#include "../../tools/usb/usb.h"

enum {
	wxID_SCAN,
	wxID_DISCONNECT,
	wxID_CONNECT,
	wxID_UNCONNECTED_LIST,
	wxID_CONNECTED_LIST
};

ConnectFrame::ConnectFrame() : wxFrame(nullptr, wxID_ANY, "Connect frame", wxDefaultPosition, wxSize(350, 420), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX) {
	// Create panel
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create buttons
	scanPorts = new wxButton(panel, wxID_SCAN, "Scan ports", wxPoint(20, 20), wxSize(200, 30));
	connectPort = new wxButton(panel, wxID_CONNECT, "Connect port", wxPoint(20, 20), wxSize(200, 30));
	disconnectPort = new wxButton(panel, wxID_DISCONNECT, "Disconnect port", wxPoint(20, 20), wxSize(200, 30));

	// Create combo boxes
	const wxString baudRates[] = { "115200", "57600", "19200", "14400", "9600" };
	const wxString databits[] = { "8", "7", "6" };
	const wxString flowControls[] = { "None", "Software", "Hardware" };
	const wxString stopBits[] = { "One", "Two" };
	const wxString parities[] = { "None", "Odd", "Even" };
	baudRateList = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), WXSIZEOF(baudRates), baudRates, wxCB_READONLY);
	databitList = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), WXSIZEOF(databits), databits, wxCB_READONLY);
	flowControlList = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), WXSIZEOF(flowControls), flowControls, wxCB_READONLY);
	stopBitList = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), WXSIZEOF(stopBits), stopBits, wxCB_READONLY);
	parityList = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), WXSIZEOF(parities), parities, wxCB_READONLY);

	// Create labels
	wxStaticText* baudRatesLabel = new wxStaticText(panel, wxID_ANY, "Baud rates:", wxPoint(20, 5));
	wxStaticText* dataBitsLabel = new wxStaticText(panel, wxID_ANY, "Data bits:", wxPoint(20, 5));
	wxStaticText* flowControlsLabel = new wxStaticText(panel, wxID_ANY, "Flow controls:", wxPoint(20, 5));
	wxStaticText* stopBitsLabel = new wxStaticText(panel, wxID_ANY, "Stop bits:", wxPoint(20, 5));
	wxStaticText* paritiesLabel = new wxStaticText(panel, wxID_ANY, "Parities:", wxPoint(20, 5));
	wxStaticText* unconnectedPortsLabel = new wxStaticText(panel, wxID_ANY, "Unconnected ports:", wxPoint(20, 5));
	wxStaticText* connectedPortsLabel = new wxStaticText(panel, wxID_ANY, "Connected ports:", wxPoint(20, 5));

	// Create listviews
	wxArrayString empty;
	unconnectedPortsList = new wxListBox(panel, wxID_UNCONNECTED_LIST, wxPoint(0, 0), wxSize(200, 160), empty, wxLB_SINGLE);
	connectedPortsList = new wxListBox(panel, wxID_CONNECTED_LIST, wxPoint(0, 0), wxSize(200, 160), empty, wxLB_SINGLE);

	// Create sizers
	wxBoxSizer* verticalLeftSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* verticalRightSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

	// Add buttons to the left
	verticalLeftSizer->Add(scanPorts, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(connectPort, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(disconnectPort, 0, wxALL | wxLEFT, 2);

	// Add drop downs to the left
	verticalLeftSizer->Add(baudRatesLabel, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(baudRateList, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(dataBitsLabel, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(databitList, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(flowControlsLabel, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(flowControlList, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(stopBitsLabel, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(stopBitList, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(paritiesLabel, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(parityList, 0, wxALL | wxLEFT, 2);

	// Add list boxes to the right
	verticalRightSizer->Add(unconnectedPortsLabel, 0, wxALL | wxLEFT, 2);
	verticalRightSizer->Add(unconnectedPortsList, 0, wxALL | wxLEFT, 2);
	verticalRightSizer->Add(connectedPortsLabel, 0, wxALL | wxLEFT, 2);
	verticalRightSizer->Add(connectedPortsList, 0, wxALL | wxLEFT, 2);

	// Add vertical into horizontal
	horizontalSizer->Add(verticalLeftSizer, 0, wxALL | wxLEFT, 2);
	horizontalSizer->Add(verticalRightSizer, 0, wxALL | wxLEFT, 2);

	// Attach
	panel->SetSizer(horizontalSizer);

	// Binds
	scanPorts->Bind(wxEVT_BUTTON, &ConnectFrame::ScanPorts, this, wxID_SCAN);
	connectPort->Bind(wxEVT_BUTTON, &ConnectFrame::OpenConnection, this, wxID_CONNECT);
	disconnectPort->Bind(wxEVT_BUTTON, &ConnectFrame::CloseConnection, this, wxID_DISCONNECT);
	unconnectedPortsList->Bind(wxEVT_COMBOBOX, &ConnectFrame::SelectedUnconnectedPort, this, wxID_UNCONNECTED_LIST);
	connectedPortsList->Bind(wxEVT_COMBOBOX, &ConnectFrame::SelectedConnectedPort, this, wxID_CONNECTED_LIST);

	// Check if we have some connection
	std::vector<std::string> connectedPorts = USB_getConnectedPorts();
	for (const auto& connectedPort : connectedPorts) {
		connectedPortsList->Append(connectedPort);
	}
}

void ConnectFrame::ScanPorts(wxCommandEvent& event) {
	std::vector<std::string> ports = USB_getUnconnectedPorts();
	unconnectedPortsList->Clear();
	for (const auto& port : ports) {
		unconnectedPortsList->Append(port);
	}
}

void ConnectFrame::OpenConnection(wxCommandEvent& event) {
	const std::string port = unconnectedPortsList->GetStringSelection().ToStdString();
	int baudrate;
	baudRateList->GetStringSelection().ToInt(&baudrate);
	int dataBit;
	databitList->GetStringSelection().ToInt(&dataBit);
	const unsigned int flowControl = stopBitList->GetSelection();
	const unsigned int stopBit = stopBitList->GetSelection();
	const unsigned int parity = parityList->GetSelection();
	if (USB_openConnection(port.c_str(), baudrate, dataBit, flowControl, stopBit, parity)) {
		// Remove the port from the unconnected and add it to connected;
		unconnectedPortsList->Delete(unconnectedPortsList->GetSelection());
		connectedPortsList->Append(port);
		wxMessageBox("Connected to port: " + port, "Success", wxOK | wxICON_INFORMATION);
	}
	else {
		wxMessageBox("Could not connect to: " + port, "Fail", wxOK | wxICON_ERROR);
	}
}

void ConnectFrame::CloseConnection(wxCommandEvent& event) {
	const std::string port = connectedPortsList->GetStringSelection().ToStdString();
	if (USB_closeConnection(port.c_str())) {
		connectedPortsList->Delete(connectedPortsList->GetSelection());
		wxMessageBox("Disconnected from port: " + port, "Success", wxOK | wxICON_INFORMATION);
	}
	else {
		wxMessageBox("Could not disconnect from: " + port, "Fail", wxOK | wxICON_ERROR);
	}
}

void ConnectFrame::SelectedUnconnectedPort(wxCommandEvent& event) {
	disconnectPort->Enable(false);
	connectPort->Enable(true);
	baudRateList->Enable(true);
	baudRateList->SetSelection(0);
	databitList->Enable(true);
	databitList->SetSelection(0);
	flowControlList->Enable(true);	
	flowControlList->SetSelection(0);
	stopBitList->Enable(true);
	stopBitList->SetSelection(0);
	parityList->Enable(true);
	parityList->SetSelection(0);
}

void ConnectFrame::SelectedConnectedPort(wxCommandEvent& event) {
	const std::string port = connectedPortsList->GetStringSelection().ToStdString();
	disconnectPort->Enable(true);
	connectPort->Enable(false);
	baudRateList->SetStringSelection(std::to_string(USB_getBaudRate(port.c_str())));
	baudRateList->Enable(false);
	databitList->SetStringSelection(std::to_string(USB_getDataBit(port.c_str())));
	databitList->Enable(false);
	flowControlList->SetStringSelection(std::to_string(USB_getFlowControl(port.c_str())));
	flowControlList->Enable(false);
	stopBitList->SetStringSelection(std::to_string(USB_getStopBit(port.c_str())));
	stopBitList->Enable(false);
	parityList->SetStringSelection(std::to_string(USB_getParity(port.c_str())));
	parityList->Enable(false);
}