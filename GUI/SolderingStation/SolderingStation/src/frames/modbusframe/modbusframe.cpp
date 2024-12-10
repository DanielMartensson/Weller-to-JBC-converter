
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
	analogInputGrid = CreateAnalogInputGrid(panel, 3);

	// Create a parameters grid
	parameterGrid = CreateAnalogInputCalibrationGrid(panel, 3, 4095);

	// Set sizers
	wxBoxSizer* verticalLeftSizer = new wxBoxSizer(wxVERTICAL);
	verticalLeftSizer->Add(modbusPorts, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(analogInputGrid, 0, wxALL | wxLEFT, 2);
	verticalLeftSizer->Add(parameterGrid, 0, wxALL | wxLEFT, 2);

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

wxGrid* ModbusFrame::CreateAnalogInputGrid(wxPanel* panel, const unsigned int rows) {
	wxGrid* grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(rows, 3);
	grid->SetColLabelValue(0, "Analog input name");
	grid->SetColLabelValue(1, "Raw value");
	grid->SetColLabelValue(2, "Real value");
	grid->AutoSizeColumns();

	for (unsigned int i = 0; i < rows; i++) {
		grid->SetReadOnly(i, 0); // Analog input name
		grid->SetReadOnly(i, 1); // Raw value
		grid->SetReadOnly(i, 2); // Read value
	}

	return grid;
}

wxGrid* ModbusFrame::CreateAnalogInputCalibrationGrid(wxPanel* panel, const unsigned int rows, const unsigned int maxADC) {
	wxGrid* grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(rows, 5);
	grid->SetColLabelValue(0, "Analog input name");
	grid->SetColLabelValue(1, "Max raw");
	grid->SetColLabelValue(2, "Min raw");
	grid->SetColLabelValue(3, "Max real");
	grid->SetColLabelValue(4, "Min real");
	grid->AutoSizeColumns();

	for (unsigned int i = 0; i < rows; i++) {
		grid->SetReadOnly(i, 0); // Analog input name
		grid->SetCellEditor(i, 1, new wxGridCellNumberEditor(0, maxADC)); // Max raw
		grid->SetCellEditor(i, 2, new wxGridCellNumberEditor(0, maxADC)); // Min raw
		grid->SetCellEditor(i, 3, new wxGridCellNumberEditor()); // Max real
		grid->SetCellEditor(i, 4, new wxGridCellNumberEditor()); // Min real
	}

	return grid;
}

void ModbusFrame::SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const float value) {
	grid->SetCellValue(row, column, wxString::FromCDouble(value));
}

void ModbusFrame::SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const char value[]) {
	grid->SetCellValue(row, column, wxString::FromAscii(value));
}

float ModbusFrame::GetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column) {
	double value;
	grid->GetCellValue(row, column).ToCDouble(&value);
	return static_cast<float>(value);
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
			SetValueGrid(analogInputGrid, 0, 0, "Setpoint");
			SetValueGrid(analogInputGrid, 0, 1, readSetpointRaw());
			SetValueGrid(analogInputGrid, 0, 2, readSetpoint());

			// Parameters
			float maxRaw = GetValueGrid(parameterGrid, 0, 0);


			//wxString maxRaw = analogInputGrid->GetCellValue(0, 3);
			//wxString minRaw = analogInputGrid->GetCellValue(0, 4);
			//wxString maxReal = analogInputGrid->GetCellValue(0, 5);
			//wxString minReal = analogInputGrid->GetCellValue(0, 6);
			
			
		}
	}
}
