#include "gridframe.h"

wxGrid* GridFrame::CreateAnalogInputGrid(wxPanel* panel, const unsigned int rows) {
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

wxGrid* GridFrame::CreateAnalogInputCalibrationGrid(wxPanel* panel, const unsigned int rows, const unsigned int maxADC) {
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

wxGrid* GridFrame::CreateDigitalInputGrid(wxPanel* panel, const unsigned int rows) {
	wxGrid* grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(rows, 2);
	grid->SetColLabelValue(0, "Digital input name");
	grid->SetColLabelValue(1, "Active");
	grid->AutoSizeColumns();

	for (unsigned int i = 0; i < rows; i++) {
		grid->SetReadOnly(i, 0); // Digital input name
		grid->SetReadOnly(i, 1); // Active
	}

	return grid;
}

wxGrid* GridFrame::CreateDigitalOutputGrid(wxPanel* panel, const unsigned int rows) {
	wxGrid* grid = new wxGrid(panel, wxID_ANY);
	grid->CreateGrid(rows, 2);
	grid->SetColLabelValue(0, "Digital output name");
	grid->SetColLabelValue(1, "Active");
	grid->AutoSizeColumns();

	for (unsigned int i = 0; i < rows; i++) {
		grid->SetReadOnly(i, 0); // Digital output name
		grid->SetReadOnly(i, 1); // Active
	}

	return grid;
}

void GridFrame::SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const float value) {
	grid->SetCellValue(row, column, wxString::FromCDouble(value));
}

void GridFrame::SetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column, const char value[]) {
	grid->SetCellValue(row, column, wxString::FromAscii(value));
}

float GridFrame::GetValueGrid(wxGrid* grid, const unsigned int row, const unsigned int column) {
	double value;
	grid->GetCellValue(row, column).ToCDouble(&value);
	return static_cast<float>(value);
}

