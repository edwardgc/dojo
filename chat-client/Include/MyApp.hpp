/*
 * MyApp.hpp
 *
 *  Created on: 2017Äê9ÔÂ12ÈÕ
 *      Author: cguo005
 */
#pragma once
#include <wx/wx.h>
#include <memory>

class ChatClient;

class MyApp: public wxApp {
public:
    MyApp(std::shared_ptr<ChatClient> p_client);
	virtual bool OnInit();
private:
	std::shared_ptr<ChatClient> m_client;
};

DECLARE_APP(MyApp)
