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
#include "ChatClient.hpp"

using namespace std;

MainFrame::MainFrame(const wxString& p_title, shared_ptr<ChatClient> p_client)
        : wxFrame(NULL, wxID_ANY, p_title, wxDefaultPosition, wxSize(700, 500)), m_client(p_client)
{
    wxPanel * panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer * vbox = new wxBoxSizer(wxVERTICAL);

    m_content = new wxTextCtrl(panel, wxID_ANY, wxEmptyString,
                               wxDefaultPosition,
                               wxDefaultSize,
                               wxTE_AUTO_URL | wxTE_MULTILINE | wxTE_READONLY);

    wxFont font { 16, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL,
                  wxFONTWEIGHT_NORMAL };
    m_content->SetFont(font);
    vbox->Add(m_content, 1, wxEXPAND | wxALL, 10);

    m_input = new wxTextCtrl(panel, wxID_ANY, wxEmptyString,
                             wxDefaultPosition,
                             wxDefaultSize, wxTE_PROCESS_ENTER);
    m_input->SetFont(font);

    vbox->Add(m_input, 0, wxEXPAND | wxALL, 10);

    Connect(wxID_ANY, wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(this->MainFrame::onEnter));

    panel->SetSizer(vbox);

    Centre();
    m_input->SetFocus();

    m_client->setReceiver(this);
}

void MainFrame::onReceive(std::string msg)
{
    cout << msg << endl;
    m_content->AppendText(msg);
    m_content->AppendText("\n");
}

void MainFrame::onEnter(wxCommandEvent&)
{
    cout << m_input->GetValue().ToStdString() << endl;
    m_client->write(m_input->GetValue().ToStdString());
    m_input->Clear();
}

MainFrame::~MainFrame()
{
    m_client->close();
}
