/*
 * MyApp.cpp
 *
 *  Created on: 2017��9��12��
 *      Author: cguo005
 */

#include <memory>
#include <wx/wx.h>
#include "MyApp.hpp"
#include "Main.hpp"
#include "WatchObserver.hpp"
#include "GuiObserver.hpp"

using namespace std;

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
	MainFrame * main = new MainFrame(wxT("Nokia Watch"));

	shared_ptr<WatchObserver> observer = make_shared<WatchObserver>();
	main->subscribe(observer);

	shared_ptr<GuiObserver> guiObserver = make_shared<GuiObserver>();
	main->subscribe(guiObserver);

	main->Show(true);

	return true;
}

