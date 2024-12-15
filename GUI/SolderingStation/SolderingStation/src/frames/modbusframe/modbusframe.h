#pragma once


#include "../../tools/tools.h"
#include "../toolsframe/toolsframe.h"
#include <wx/spinctrl.h>

class ModbusFrame : public wxFrame, GridFrame, VectorTools
{
private:
    // Fields
    COMMUNICATION_DATA& communicationData;

    // Arrays
    uint16_t analogInputs[13];
    uint8_t digitalInputs[1];
    uint8_t digitalOutputs[2];
    uint16_t parameters[31];

    /* Analog inputs */
    bool receiveAnalogInputs();
    bool receiveDigitalInputs();
    bool receiveDigitalOutputs();
    bool receiveParameters();
    float readTemperatureRaw();
    float readSetpointRaw();
    float readCurrentRaw();
    float readStateX0();
    float readStateX1();
    float readTemperatureReal();
    float readSetpointReal();
    float readCurrentReal();

    /* Digital inputs */
    bool receiveNSleep();

    /* Digital outputs */
    bool receiveLeakageActive();
    bool receiveLedGreen();

    // Items
    wxComboBox* modbusPorts;
    wxComboBox* operationComboBox;
    wxTimer* timer;
    wxSpinCtrl* limitCounter;
    wxGrid* analogInputGrid;
    wxButton* startLoggingButton;
    wxButton* stopLoggingButton;
    wxGrid* parameterGrid;
    wxGrid* digitalInputGrid;
    wxGrid* digitalOutputGrid;

    // For plot
    std::vector<wxString> legend;
    std::vector<std::vector<double>&> data2D;
    std::vector<double> x0;
    std::vector<double> x1;
    std::vector<double> w0;
    std::vector<double> w1;
    std::vector<double> w2;
    std::vector<double> temperature;
    std::vector<double> setpoint;
    std::vector<double> current;

    // Functions
    void OnClose(wxCloseEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnReceive(wxCommandEvent& event);
    void OnSend(wxCommandEvent& event);
    void OnStart(wxCommandEvent& event);
    void OnStop(wxCommandEvent& event);
    void OnSelect(wxCommandEvent& event);

public:
    ModbusFrame(COMMUNICATION_DATA& communicationData);

    std::vector<wxString>& GetLegend();
    std::vector<std::vector<double>&>& GetData2D();

};