/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <IReceiver.hpp>
#include <wx/event.h>
#include <wx/msw/frame.h>
#include <wx/string.h>
#include <memory>
#include <string>

class ChatClient;

class MainFrame: public wxFrame, IReceiver
{
public:
    MainFrame(const wxString& p_title, std::shared_ptr<ChatClient> p_client);
    void onReceive(std::string msg);
    void onEnter(wxCommandEvent&);
    ~MainFrame();
private:
    std::shared_ptr<ChatClient> m_client;
    wxTextCtrl* m_content;
    wxTextCtrl* m_input;
};




