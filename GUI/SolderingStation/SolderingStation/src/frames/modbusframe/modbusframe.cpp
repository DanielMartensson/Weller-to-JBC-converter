
#include "modbusframe.h"

enum {
	wxID_SCAN,
	wxID_DISCONNECT,
	wxID_CONNECT,
	wxID_UNCONNECTED_LIST,
	wxID_CONNECTED_LIST
};

typedef enum {
	PARAMETER_ESTIMATION,
	STATE_ESTIMATION,
	CONTROL_FEEDBACK,
	STATE_ESTIMATION_AND_CONTROL_FEEDBACK,
	RECOMPUTE_MODEL,
	SAVE_REGISTER_TO_MEMORY
}OPERATION;

ModbusFrame::ModbusFrame(COMMUNICATION_DATA& communicationData) : wxFrame(nullptr, wxID_ANY, "Connect frame", wxDefaultPosition, wxSize(350, 420), wxDEFAULT_FRAME_STYLE), communicationData(communicationData) {
	// Create panel
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create timer
	timer = new wxTimer(this);

	// Combobox
	modbusPorts = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), 0, NULL, wxCB_READONLY);
	operationComboBox = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), { "Parameter estimation", "State estimation", "Control feedback", "State estimation & control feedback", "Save parameters"}, wxCB_READONLY);

	// Update ports
	modbusPorts->Clear();
	for (const auto& port : this->communicationData.ports) {
		modbusPorts->Append(port);
	}

	// Grids
	analogInputGrid = CreateAnalogInputGrid(panel, 3);
	parameterGrid = CreateAnalogInputCalibrationGrid(panel, 3, 4095);
	digitalInputGrid = CreateDigitalInputGrid(panel, 1);
	digitalOutputGrid = CreateDigitalOutputGrid(panel, 2);

	// Buttons
	startLoggingButton = new wxButton(panel, wxID_ABORT, "Start logging");
	stopLoggingButton = new wxButton(panel, wxID_ABOUT, "Stop logging");
	wxButton* sendParameterButton = new wxButton(panel, wxID_SAVE, "Send parameters");
	wxButton* receiveParameterButton = new wxButton(panel, wxID_NEW, "Receive parameters");

	// Counters
	limitCounter = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(50, 50), wxSize(150, 30));
	limitCounter->SetRange(0, 1000);
	limitCounter->SetValue(100);

	// Create sizers
	wxBoxSizer* verticalSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* horizontalButtonSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* horizontalAnalogSizer = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* horizontalDigitalSizer = new wxBoxSizer(wxHORIZONTAL);

	// Combo and buttons
	horizontalButtonSizer->Add(modbusPorts, 0, wxALL, 2);
	horizontalButtonSizer->Add(startLoggingButton, 0, wxALL, 2);
	horizontalButtonSizer->Add(stopLoggingButton, 0, wxALL, 2);
	horizontalButtonSizer->Add(sendParameterButton, 0, wxALL, 2);
	horizontalButtonSizer->Add(receiveParameterButton, 0, wxALL, 2);
	horizontalButtonSizer->Add(operationComboBox, 0, wxALL, 2);

	// Analog sizers
	horizontalAnalogSizer->Add(analogInputGrid, 0, wxALL, 2);
	horizontalAnalogSizer->Add(parameterGrid, 0, wxALL, 2);

	// Digital sizers
	horizontalDigitalSizer->Add(digitalInputGrid, 0, wxALL, 2);
	horizontalDigitalSizer->Add(digitalOutputGrid, 0, wxALL, 2);

	// Set sizers
	verticalSizer->Add(horizontalButtonSizer, 0, wxALL, 2);
	verticalSizer->Add(horizontalAnalogSizer, 0, wxALL, 2);
	verticalSizer->Add(horizontalDigitalSizer, 0, wxALL, 2);

	// Attach
	panel->SetSizer(verticalSizer);

	// Events
	Bind(wxEVT_CLOSE_WINDOW, &ModbusFrame::OnClose, this);
	Bind(wxEVT_TIMER, &ModbusFrame::OnTimer, this);
	sendParameterButton->Bind(wxEVT_BUTTON, &ModbusFrame::OnSend, this);
	receiveParameterButton->Bind(wxEVT_BUTTON, &ModbusFrame::OnReceive, this);
	startLoggingButton->Bind(wxEVT_BUTTON, &ModbusFrame::OnStart, this);
	stopLoggingButton->Bind(wxEVT_BUTTON, &ModbusFrame::OnStop, this);
	operationComboBox->Bind(wxEVT_COMBOBOX, &ModbusFrame::OnSelect, this);

	// Initial
	startLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_GREEN));
	startLoggingButton->Enable(true);
	stopLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_RED));
	stopLoggingButton->Enable(false);
}

void ModbusFrame::OnClose(wxCloseEvent& event) {
	timer->Stop();
	this->Destroy();
}

std::vector<wxString>& ModbusFrame::GetLegend() {
	return legend;
}

std::vector<std::vector<double>&>& ModbusFrame::GetData2D() {
	return data2D;
}


void ModbusFrame::OnSelect(wxCommandEvent& event) {
	// Clear all
	legend.clear();
	data2D.clear();

	const int selection = operationComboBox->GetSelection();
	switch (selection) {
	case PARAMETER_ESTIMATION:
		legend.push_back("w0");
		legend.push_back("w1");
		legend.push_back("w2");
		legend.push_back("Setpoint");
		legend.push_back("Temperature");
		data2D.push_back(w0);
		data2D.push_back(w1);
		break;
	case STATE_ESTIMATION:
		legend.push_back("x0");
		legend.push_back("x1");
		legend.push_back("Setpoint");
		legend.push_back("Temperature");
		data2D.push_back(x0);
		data2D.push_back(x1);
		data2D.push_back(setpoint);
		data2D.push_back(temperature);
		break;
	case CONTROL_FEEDBACK:
		break;
	case STATE_ESTIMATION_AND_CONTROL_FEEDBACK:
		break;
	case RECOMPUTE_MODEL:
		break;
	case SAVE_REGISTER_TO_MEMORY:
		break;
	default:
		break;
	}
}

void ModbusFrame::OnTimer(wxTimerEvent& event) {
	// Get selected port 
	const std::string port = modbusPorts->GetStringSelection().ToStdString();
	const bool isOpen = this->communicationData.isOpen[port];

	if (!isOpen) {
		wxCommandEvent event;
		OnStop(event);
		return;
	}

	// Call modbus commands
	if (isOpen) {
		// Set the temporary port for modbus
		USB_setTemporaryPort(port.c_str());

		// Call modbus
		receiveAnalogInputs();
		receiveDigitalInputs();
		receiveDigitalOutputs();
		receiveParameters();

		// Read analog inputs
		const float rawSetpoint = readSetpointRaw();
		const float realSetpoint = readSetpointReal();
		const float rawTemperature = readTemperatureRaw();
		const float realTemperature = readTemperatureReal();
		const float rawCurrent = readCurrentRaw();
		const float realCurrent = readCurrentReal();
		const float stateX0 = readStateX0();
		const float stateX1 = readStateX1();

		// Set
		SetValueGrid(analogInputGrid, 0, 0, "Setpoint");
		SetValueGrid(analogInputGrid, 0, 1, rawSetpoint);
		SetValueGrid(analogInputGrid, 0, 2, realSetpoint);
		SetValueGrid(analogInputGrid, 1, 0, "Temperature");
		SetValueGrid(analogInputGrid, 1, 1, rawTemperature);
		SetValueGrid(analogInputGrid, 1, 2, realTemperature);
		SetValueGrid(analogInputGrid, 2, 0, "Current");
		SetValueGrid(analogInputGrid, 2, 1, rawCurrent);
		SetValueGrid(analogInputGrid, 3, 2, realCurrent);

		// Parameters
		SetValueGrid(parameterGrid, 0, 0, "Setpoint");
		const float minSetpointRaw = GetValueGrid(parameterGrid, 0, 1);
		const float maxSetpointRaw = GetValueGrid(parameterGrid, 0, 2);
		const float minSetpointReal = GetValueGrid(parameterGrid, 0, 3);
		const float maxSetpointReal = GetValueGrid(parameterGrid, 0, 4);
		SetValueGrid(parameterGrid, 1, 0, "Temperature");
		const float minTemperatureRaw = GetValueGrid(parameterGrid, 1, 1);
		const float maxTemperatureRaw = GetValueGrid(parameterGrid, 1, 2);
		const float minTemperatureReal = GetValueGrid(parameterGrid, 1, 3);
		const float maxTemperatureReal = GetValueGrid(parameterGrid, 1, 4);
		SetValueGrid(parameterGrid, 2, 0, "Current");
		const float minCurrentRaw = GetValueGrid(parameterGrid, 2, 1);
		const float maxCurrentRaw = GetValueGrid(parameterGrid, 2, 2);
		const float minCurrentReal = GetValueGrid(parameterGrid, 2, 3);
		const float maxCurrentReal = GetValueGrid(parameterGrid, 2, 4);	

		// Convert parameters
		float_to_uint16(minSetpointRaw, &parameters[1], &parameters[0]);
		float_to_uint16(maxSetpointRaw, &parameters[3], &parameters[2]);
		float_to_uint16(minSetpointReal, &parameters[5], &parameters[4]);
		float_to_uint16(maxSetpointReal, &parameters[7], &parameters[6]);
		float_to_uint16(minTemperatureRaw, &parameters[9], &parameters[8]);
		float_to_uint16(maxTemperatureRaw, &parameters[11], &parameters[10]);
		float_to_uint16(minTemperatureReal, &parameters[13], &parameters[12]);
		float_to_uint16(maxTemperatureReal, &parameters[15], &parameters[14]);
		float_to_uint16(minCurrentRaw, &parameters[17], &parameters[16]);
		float_to_uint16(maxCurrentRaw, &parameters[19], &parameters[18]);
		float_to_uint16(minCurrentReal, &parameters[21], &parameters[20]);
		float_to_uint16(maxCurrentReal, &parameters[23], &parameters[22]);

		// Operation
		parameters[24] = operationComboBox->GetSelection();
		
		// Inputs
		SetValueGrid(digitalInputGrid, 0, 0, "Sleep");
		SetValueGrid(digitalInputGrid, 0, 1, receiveNSleep() ? "On" : "Off");

		// Outputs
		SetValueGrid(digitalOutputGrid, 0, 0, "Leakage");
		SetValueGrid(digitalOutputGrid, 0, 1, receiveLeakageActive() ? "On" : "Off");
		SetValueGrid(digitalOutputGrid, 0, 0, "LED green");
		SetValueGrid(digitalOutputGrid, 0, 1, receiveLedGreen() ? "On" : "Off");

		// Create data for the plot
		const int maxLimit = limitCounter->GetValue();
		addNewValue(x0, stateX0, maxLimit);
		addNewValue(x1, stateX1, maxLimit);
		//addNewValue(w0, value, maxLimit);
		//addNewValue(w1, value, maxLimit);
		//addNewValue(w2, value, maxLimit);
		addNewValue(temperature, realTemperature, maxLimit);
		addNewValue(setpoint, realSetpoint, maxLimit);
	}	
}

void ModbusFrame::OnReceive(wxCommandEvent& event) {
	modbus_client_get_parameters(parameters, 0, sizeof(parameters) / sizeof(parameters[0]));
}

void ModbusFrame::OnSend(wxCommandEvent& event) {
	modbus_client_set_parameters(parameters, 0, sizeof(parameters) / sizeof(parameters[0]));
}

void ModbusFrame::OnStart(wxCommandEvent& event) {
	timer->Start(100);
	startLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_RED));
	startLoggingButton->Enable(false);
	stopLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_GREEN));
	stopLoggingButton->Enable(true);
}

void ModbusFrame::OnStop(wxCommandEvent& event) {
	timer->Stop();
	startLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_GREEN));
	startLoggingButton->Enable(true);
	stopLoggingButton->SetBackgroundColour(plotColours.at(PLOT_COLOUR_RED));
	stopLoggingButton->Enable(false);
}

bool ModbusFrame::receiveAnalogInputs() {
	return modbus_client_get_analog_inputs(analogInputs, 0, 9);
}

bool ModbusFrame::receiveDigitalInputs() {
	return modbus_client_get_digital_inputs(digitalInputs, 0, 1);
}

bool ModbusFrame::receiveDigitalOutputs() {
	return modbus_client_get_digital_inputs(digitalOutputs, 0, 2);
}

bool ModbusFrame::receiveParameters() {
	return modbus_client_get_parameters(parameters, 25, 31);
}

float ModbusFrame::readTemperatureRaw() {
	return static_cast<float>(analogInputs[0]);
}

float ModbusFrame::readSetpointRaw() {
	return static_cast<float>(analogInputs[1]);
}

float ModbusFrame::readStateX0() {
	return uint16_to_float(analogInputs[10], analogInputs[9]);
}

float ModbusFrame::readStateX1() {
	return uint16_to_float(analogInputs[12], analogInputs[11]);
}

float ModbusFrame::readCurrentRaw() {
	return static_cast<float>(analogInputs[2]);
}

float ModbusFrame::readTemperatureReal() {
	return uint16_to_float(analogInputs[3], analogInputs[4]);
}

float ModbusFrame::readSetpointReal() {
	return uint16_to_float(analogInputs[5], analogInputs[6]);
}

float ModbusFrame::readCurrentReal() {
	return uint16_to_float(analogInputs[7], analogInputs[8]);
}

bool ModbusFrame::receiveNSleep() {
	return digitalInputs[0] & 0x1;
}

bool ModbusFrame::receiveLeakageActive() {
	return (digitalOutputs[0] >> 0) & 0x1;
}

bool ModbusFrame::receiveLedGreen() {
	return (digitalOutputs[1] >> 1) & 0x1;
}