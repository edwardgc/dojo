/*
 * Main.cpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#include <wx/wx.h>
#include "wx/bookctrl.h"
#include "wx/display.h"
#include "LCD.hpp"
#include "Digit.hpp"

class Simple: public wxFrame {
public:
	Simple(const wxString& title);
	void showMessage(wxCommandEvent & event);
private:
	wxButton* switchBtn;
	wxButton* upBtn;
	wxButton* downBtn;
	wxStaticText* textBox;
};

class MyApp: public wxApp {
public:
	virtual bool OnInit();
};

Simple::Simple(const wxString& title) :
		wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 150)) {
	wxPanel * panel = new wxPanel(this, wxID_ANY);

	wxBoxSizer * hbox = new wxBoxSizer(wxHORIZONTAL);
	switchBtn = new wxButton(panel, wxID_NEW, _T("Switch"));

	hbox->Add(switchBtn, 2, wxEXPAND | wxALL, 5);

	LCD lcd{1212};
	const char* c = lcd.toString().c_str();
	wxString text{lcd.toString()};
	textBox =  new wxStaticText(panel, wxID_ANY, text, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

	wxFont font{20, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL};
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
}

void Simple::showMessage(wxCommandEvent & event)
{
    wxMessageDialog * dial = new wxMessageDialog(NULL, _T("Download completed"), _T("Info"), wxOK);
    dial->ShowModal();
}

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
	Simple * simple = new Simple(wxT("Nokia Watch"));
	simple->Show(true);
	return true;
}

