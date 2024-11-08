
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
    plot = new wxPlot(this, WXPLOT_TYPE_LINE, WXPLOT_FIGURE_STANDARD);

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
    plot->setPlotData(plotData);
    plot->Refresh();
}

void MainFrame::OnSize(wxSizeEvent& event) {
    // Get window size
    wxSize newSize = event.GetSize();
    wxCoord width = newSize.x;
    wxCoord height = newSize.y;

    // Redraw figure
    plot->getPlots()->getPlotFigures()->getStandard()->setPlotWidth(width);
    plot->getPlots()->getPlotFigures()->getStandard()->setPlotHeight(height);
    plot->Refresh();

}