
#include "mainframe.h"

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
    menuEdit->Append(wxID_NETWORK, "&Modbus");

    // Create the menu bar
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // Create Modbus RTU client
    modbus_set_serial_read(USB_readProcess);
    modbus_set_serial_write(USB_writeProcess);
    modbus_set_serial_port(USB_getTemporaryPort);
    modbus_client_create_RTU(1);

    // Create plot
    plot = new wxPlot(this, WXPLOT_FIGURE_2D, WXPLOT_TYPE_LINE);

    // Create timer for the 100 ms loop
    timer = new wxTimer(this);
    timer->Start(100);

    // Events
    Bind(wxEVT_MENU, &MainFrame::OnControl, this, wxID_EXECUTE);
    Bind(wxEVT_MENU, &MainFrame::OnConnect, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainFrame::OnModbus, this, wxID_NETWORK);
    Bind(wxEVT_SIZE, &MainFrame::OnSize, this);
    Bind(wxEVT_TIMER, &MainFrame::OnTimer, this);

    // Frames
    modbusFrame = new ModbusFrame(communicationData);
}

void MainFrame::OnExit(wxCommandEvent& event){
    timer->Stop();
    Close(true);
    this->Destroy();
}

void MainFrame::OnConnect(wxCommandEvent& event){
    ConnectFrame* connectFrame = new ConnectFrame(communicationData);
    connectFrame->Show();
}

void MainFrame::OnControl(wxCommandEvent& event){
    ControlFrame* controlFrame = new ControlFrame(communicationData);
    controlFrame->Show();
}

void MainFrame::OnModbus(wxCommandEvent& event) {
    modbusFrame->Show();
}

void MainFrame::OnTimer(wxTimerEvent& event){
   // Get data
   std::vector<wxString>& legendModbus = modbusFrame->GetLegend();
   std::vector<std::vector<double>&>& data2DModbus = modbusFrame->GetData2D();

   plot->setLegend(legendModbus);
   plot->setData(data2DModbus);

}

void MainFrame::OnSize(wxSizeEvent& event) {
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Set size
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
}

/*
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
        // Create data
    std::vector<std::vector<double>> data = { {0, 100, 200, 300, 400, 500}, {50, 50 , 50, 50, 1, 50},
                                              { 0, 200, 300, 400, 500, 600 }, {20, 20 , -20, 20, 0, 20} };

    // Create legend
    std::vector<wxString> legend = { "red", "green", "blue", "super svart!"};

    // Redraw figure
    */