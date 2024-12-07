
#include "modbusframe.h"

enum {
	wxID_SCAN,
	wxID_DISCONNECT,
	wxID_CONNECT,
	wxID_UNCONNECTED_LIST,
	wxID_CONNECTED_LIST
};

ModbusFrame::ModbusFrame(COMMUNICATION_DATA& communicationData) : wxFrame(nullptr, wxID_ANY, "Connect frame", wxDefaultPosition, wxSize(350, 420), wxDEFAULT_FRAME_STYLE), communicationData(communicationData) {
	// Create panel
	wxPanel* panel = new wxPanel(this, wxID_ANY);

	// Create Modbus RTU client
	modbus_set_serial_read(USB_readProcess);
	modbus_set_serial_write(USB_writeProcess);
	modbus_set_serial_port(USB_getTemporaryPort);
	modbus_client_create_RTU(1);

	// Create timer for the 100 ms loop
	timer = new wxTimer(this);
	timer->Start(100);

	// Load all modbus ports
	modbusPorts = new wxComboBox(panel, wxID_ANY, "Select an option", wxPoint(20, 20), wxSize(200, 30), 0, NULL, wxCB_READONLY);
	
	// Update ports
	modbusPorts->Clear();
	for (const auto& port : this->communicationData.ports) {
		modbusPorts->Append(port);
	}

	// Create a analogInputGrid
	analogInputGrid = new wxGrid(panel, wxID_ANY);

	// Create columns for analog inputs
	analogInputGrid->CreateGrid(3, 7); 
	analogInputGrid->SetColLabelValue(0, "Analog input name");
	analogInputGrid->SetColLabelValue(1, "Raw value");
	analogInputGrid->SetColLabelValue(2, "Real value");
	analogInputGrid->AutoSizeColumns();

	// Settings for analog input
	for (int i = 0; i < 3; i++) {
		analogInputGrid->SetReadOnly(i, 0); // Analog input name
		analogInputGrid->SetReadOnly(i, 1); // Raw value
		analogInputGrid->SetReadOnly(i, 2); // Read value
	}

	// Create a parameters grid
	parameterGrid = new wxGrid(panel, wxID_ANY);

	// Create columns for parameters
	parameterGrid->SetColLabelValue(0, "Analog input name");
	parameterGrid->SetColLabelValue(1, "Max raw");
	parameterGrid->SetColLabelValue(2, "Min raw");
	parameterGrid->SetColLabelValue(3, "Max real");
	parameterGrid->SetColLabelValue(4, "Min real");

	// Settings for parameters
	for (int i = 0; i < 3; i++) {
		parameterGrid->SetReadOnly(i, 0);
		parameterGrid->SetCellEditor(i, 1, new wxGridCellNumberEditor(0, 4095)); // Max raw
		parameterGrid->SetCellEditor(i, 2, new wxGridCellNumberEditor(0, 4095)); // Min raw
		parameterGrid->SetCellEditor(i, 3, new wxGridCellNumberEditor()); // Max real
		parameterGrid->SetCellEditor(i, 4, new wxGridCellNumberEditor()); // Min real
	}

	// Set sizers
	wxBoxSizer* verticalLeftSizer = new wxBoxSizer(wxVERTICAL);
	verticalLeftSizer->Add(modbusPorts, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(analogInputGrid, 0, wxALL | wxLEFT, 2);

	// Attach
	panel->SetSizer(verticalLeftSizer);

	// Events
	Bind(wxEVT_CLOSE_WINDOW, &ModbusFrame::OnClose, this);
	Bind(wxEVT_TIMER, &ModbusFrame::OnTimer, this);
}

void ModbusFrame::OnClose(wxCloseEvent& event) {
	timer->Stop();
	Destroy();
}

void ModbusFrame::OnTimer(wxTimerEvent& event) {
	if (this->communicationData.ports.size() > 0) {

		// Get selected port 
		const std::string port = modbusPorts->GetStringSelection().ToStdString();
		const bool isOpen = this->communicationData.isOpen[port];

		// Set the temporary port for modbus
		USB_setTemporaryPort(port.c_str());

		// Call modbus commands
		if (isOpen) {
			// Analog inputs
			receiveAnalogInputs();
			analogInputGrid->SetCellValue(0, 0, "Setpoint");
			analogInputGrid->SetCellValue(0, 1, wxString::FromCDouble(readSetpointRaw()));
			analogInputGrid->SetCellValue(0, 2, wxString::FromCDouble(readSetpoint()));
			//wxString maxRaw = analogInputGrid->GetCellValue(0, 3);
			//wxString minRaw = analogInputGrid->GetCellValue(0, 4);
			//wxString maxReal = analogInputGrid->GetCellValue(0, 5);
			//wxString minReal = analogInputGrid->GetCellValue(0, 6);
			
			
		}
	}
}
