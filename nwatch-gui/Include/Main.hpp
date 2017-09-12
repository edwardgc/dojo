/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <iostream>
#include <memory>
#include <wx/wx.h>

class IWatchObserver;

class MainFrame: public wxFrame
{
public:
    MainFrame(const wxString& title);
    ~MainFrame();
    void subscribe(std::shared_ptr<IWatchObserver> observer);
    void onSecond(wxTimerEvent& f_event);
    DECLARE_EVENT_TABLE()
private:
    void onSwitchClick(wxCommandEvent&);
    void onUpClick(wxCommandEvent&);
    void onDownClick(wxCommandEvent&);
    wxButton* switchBtn;
    wxButton* upBtn;
    wxButton* downBtn;
    wxStaticText* textBox;
//    WatchTimer* timer;
    wxTimer m_timer;

    std::vector<std::shared_ptr<IWatchObserver>> observers;
};




