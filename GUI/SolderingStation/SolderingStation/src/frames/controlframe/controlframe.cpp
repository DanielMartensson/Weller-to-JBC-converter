#include "controlframe.h"

ControlFrame::ControlFrame(COMMUNICATION_DATA& communicationData) : wxFrame(nullptr, wxID_ANY, "Control frame", wxDefaultPosition), communicationData(communicationData) {
	// Create panel
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create start button
	startButton = new wxButton(panel, wxID_EXECUTE);

	// Create stop button
	stopButton = new wxButton(panel, wxID_STOP, "Stop");

	// Create sizer
	wxBoxSizer* sizerHorizontal = new wxBoxSizer(wxHORIZONTAL);

	// Attach
	sizerHorizontal->Add(startButton, 0, wxALL | wxLEFT, 2);
	sizerHorizontal->Add(stopButton, 0, wxALL | wxLEFT, 2);

	// Sett all
	panel->SetSizer(sizerHorizontal);

	// Events
	Bind(wxEVT_BUTTON, &ControlFrame::OnStart, this, wxID_EXECUTE);
	Bind(wxEVT_BUTTON, &ControlFrame::OnStop, this, wxID_STOP);

	// Enable
	EnableComponents(this->communicationData.isStarted);
}

void ControlFrame::OnStart(wxCommandEvent& event) {

	if (this->communicationData.ports.size() > 0) {
		EnableComponents(true);
		this->communicationData.isStarted = true;
	}
	else {
		wxMessageBox("You're not connected to a port!", "Not connected", wxOK | wxICON_ERROR);
	}
}

void ControlFrame::OnStop(wxCommandEvent& event) {
	EnableComponents(false);
	this->communicationData.isStarted = false;
}

void ControlFrame::EnableComponents(const bool enable) {
	startButton->Enable(!enable);
	stopButton->Enable(enable);
}