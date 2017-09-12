/*
 * Main.cpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#include <wx/wx.h>
#include <wx/bookctrl.h>
#include <wx/display.h>
#include <future>
#include <mutex>
#include <chrono>
#include "Main.hpp"
#include "LCD.hpp"
#include "Digit.hpp"
#include "IWatchObserver.hpp"

using namespace std;

MainFrame::MainFrame(const wxString& title) :
        wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 150)),
        m_timer(this)
{
    wxPanel * panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer * hbox = new wxBoxSizer(wxHORIZONTAL);
    switchBtn = new wxButton(panel, wxID_NEW, _T("Switch"));

    hbox->Add(switchBtn, 2, wxEXPAND | wxALL, 5);

    LCD lcd { 1212 };
    wxString text { lcd.toString() };
    textBox = new wxStaticText(panel, wxID_ANY, text, wxDefaultPosition,
            wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

    wxFont font { 20, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL };
    textBox->SetFont(font);

    wxBoxSizer * vbox = new wxBoxSizer(wxVERTICAL);

    hbox->Add(textBox, 6, wxEXPAND | wxALL, 5);
    upBtn = new wxButton(panel, wxID_UP, _T("Up"));
    downBtn = new wxButton(panel, wxID_DOWN, _T("Down"));

    vbox->Add(upBtn, 1, wxSTRETCH_NOT | wxALL, 5);
    vbox->Add(downBtn, 1, wxSTRETCH_NOT | wxALL, 5);
    hbox->Add(vbox, 2, wxEXPAND | wxALL, 5);
    panel->SetSizer(hbox);

    Centre();

    Connect(wxID_NEW, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(this->MainFrame::onSwitchClick));
    Connect(wxID_UP, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(this->MainFrame::onUpClick));
    Connect(wxID_DOWN, wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(this->MainFrame::onDownClick));

    m_timer.Start(1000);
}

void MainFrame::subscribe(shared_ptr<IWatchObserver> observer)
{
    observers.push_back(observer);
}

void MainFrame::onSwitchClick(wxCommandEvent&)
{
    for_each(observers.begin(), observers.end(), [](auto& o)
    {   o->onSwitchClick();});
}

void MainFrame::onUpClick(wxCommandEvent&)
{
    for_each(observers.begin(), observers.end(), [](auto& o)
    {   o->onUpClick();});
}

void MainFrame::onDownClick(wxCommandEvent&)
{
    for_each(observers.begin(), observers.end(), [](auto& o)
    {   o->onDownClick();});
}

void MainFrame::onSecond(wxTimerEvent& f_event)
{
    string rt;
    for_each(observers.begin(), observers.end(), [&rt](auto& o)
    {   rt += o->onSecond();});
    if(!rt.empty())
        textBox->SetLabelText(rt);
}

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_TIMER(wxID_ANY, MainFrame::onSecond)
END_EVENT_TABLE()
