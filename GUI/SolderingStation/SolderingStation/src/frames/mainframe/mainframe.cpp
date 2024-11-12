
#include "mainframe.h"
#include "../connectframe/connectframe.h"

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Main frame")
{
    // File menu
    wxMenu* menuFile = new wxMenu();
    menuFile->Append(wxID_FILE, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    // Edit manu
    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append(wxID_OPEN, "&Connect");

    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuEdit, "&Edit");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    // Create plot
    plot = new wxPlot(this, WXPLOT_TYPE_SPLINE_SCATTER);

    // Events
    Bind(wxEVT_MENU, &MainFrame::OnHello, this, wxID_FILE);
    Bind(wxEVT_MENU, &MainFrame::OnConnect, this, wxID_OPEN);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_SIZE, &MainFrame::OnSize, this);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MainFrame::OnConnect(wxCommandEvent& event)
{
    ConnectFrame* connectFrame = new ConnectFrame();
    connectFrame->Show();
}

void MainFrame::OnHello(wxCommandEvent& event)
{
    std::vector<std::vector<double>> plotData = { {0, 400},{0, 500} };
    plot->Refresh();
}

void MainFrame::OnSize(wxSizeEvent& event) {
    // If we don't use this, then refresh won't work
    event.Skip();

    // Get window size
    wxCoord startWidth = 0, startHeight = 0, endWidth, endHeight;
    GetClientSize(&endWidth, &endHeight);

    // Create data
    std::vector<std::vector<double>> data = { {0, 100, 200, 300, 400, 500}, {50, 150 , 40, -200, 3330, 420},
                                              { 0, 200, 300, 400, 500, 607 }, {20, 15 , 100, -301, 1000, 420} };


    // Redraw figure
    plot->setFontSize(12);
    plot->setTitle("hello");
    //plot->setYlabel("hello");
    //plot->setXlabel("hello");
    plot->setTicks(6);
    plot->gridOn(true);
    plot->setRadius(10);
    plot->fillCircles(true);
    plot->setPlotStartWidth(startWidth);
    plot->setPlotStartHeight(startHeight);
    plot->setPlotEndWidth(endWidth);
    plot->setPlotEndHeight(endHeight);
    plot->setData(data);
    plot->Refresh();

}