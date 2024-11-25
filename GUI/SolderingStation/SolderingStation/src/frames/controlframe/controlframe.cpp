#include "controlframe.h"

static bool isStarted = false;

ControlFrame::ControlFrame() : wxFrame(nullptr, wxID_ANY, "Control frame", wxDefaultPosition) {
	// Create panel
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create start button
	startButton = new wxButton(panel, wxID_EXECUTE);

	// Create stop button
	stopButton = new wxButton(panel, wxID_STOP, "Stop");

	// Create slider
	pwmSlider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxSize(300, 50), wxSL_HORIZONTAL | wxSL_LABELS);

	// Create sizer
	wxBoxSizer* sizerHorizontal = new wxBoxSizer(wxHORIZONTAL);

	// Attach
	sizerHorizontal->Add(startButton, 0, wxALL | wxLEFT, 2);
	sizerHorizontal->Add(stopButton, 0, wxALL | wxLEFT, 2);
	sizerHorizontal->Add(pwmSlider, 0, wxALL | wxLEFT, 2);

	// Sett all
	panel->SetSizer(sizerHorizontal);

	// Events
	Bind(wxEVT_BUTTON, &ControlFrame::OnStart, this, wxID_EXECUTE);
	Bind(wxEVT_BUTTON, &ControlFrame::OnStop, this, wxID_STOP);

	// Enable
	EnableComponents(isStarted);
}

void ControlFrame::OnStart(wxCommandEvent& event) {
	EnableComponents(true);
}

void ControlFrame::OnStop(wxCommandEvent& event) {
	EnableComponents(false);
}

void ControlFrame::EnableComponents(const bool enable) {
	startButton->Enable(!enable);
	stopButton->Enable(enable);
	pwmSlider->Enable(enable);
	isStarted = enable;
	if (!enable) {
		pwmSlider->SetValue(0);
	}

}