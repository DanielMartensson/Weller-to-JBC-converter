
#include "mainframe.h"
#include "../frames.h"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Main frame")
{
    // File menu
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_FILE, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    // Edit menu
    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append(wxID_OPEN, "&Connect");
    menuEdit->Append(wxID_EXECUTE, "&Control");

    // Create the menu bar
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // Create plot
    plot = new wxPlot(this, WXPLOT_FIGURE_2D, WXPLOT_TYPE_LINE);

    // Create Modbus RTU client
    createModbusClient();

    // Create timer for the 100 ms loop
    wxTimer* timer = new wxTimer(this);
    timer->Start(100);

    // Events
    Bind(wxEVT_MENU, &MainFrame::OnControl, this, wxID_EXECUTE);
    Bind(wxEVT_MENU, &MainFrame::OnConnect, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_SIZE, &MainFrame::OnSize, this);
    Bind(wxEVT_TIMER, &MainFrame::OnTimer, this);
}

void MainFrame::OnExit(wxCommandEvent& event){
    Close(true);
}

void MainFrame::OnConnect(wxCommandEvent& event){
    ConnectFrame* connectFrame = new ConnectFrame(communicationData);
    connectFrame->Show();
}

void MainFrame::OnControl(wxCommandEvent& event){
    ControlFrame* controlFrame = new ControlFrame(communicationData);
    controlFrame->Show();
}

void MainFrame::OnTimer(wxTimerEvent& event){
    if (communicationData.isStarted && communicationData.isOpen) {
        // Receive temperature signal
        communicationData.temperature = receiveTemperature(communicationData.port);

        // Receive current signal
        communicationData.current = receiveCurrent(communicationData.port);

        // Receive setpoint signal
        communicationData.setpoint = receiveSetpoint(communicationData.port);

        // Receive parameter estimation

        // Receive control signal

        // Receive state estimation

        // Write on plot
    }
}

void MainFrame::OnSize(wxSizeEvent& event) {
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Create data
    std::vector<std::vector<double>> data = { {0, 100, 200, 300, 400, 500}, {50, 50 , 50, 50, 1, 50},
                                              { 0, 200, 300, 400, 500, 600 }, {20, 20 , -20, 20, 0, 20} };

    // Create legend
    std::vector<wxString> legend = { "red", "green", "blue", "super svart!"};

    // Redraw figure
    plot->setFontSize(10);
    plot->setTitle("hellofdsfdfgdgfdgfd");
    plot->setYlabel("hellogfdgfdgfdgfdgdfgd");
    plot->setXlabel("hellogfdgfdfdsffgdsgfdgfdgfd");
    plot->setTicks(10);
    plot->legendOn(true);
    plot->setLegend(legend, PLACEMENT_CENTRE);
    plot->gridOn(true);
    plot->setRadius(3);
    plot->fillCircles(false);
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->setData(data);
    plot->Refresh();

}