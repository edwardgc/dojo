/*
 * MyApp.hpp
 *
 *  Created on: 2017��9��12��
 *      Author: cguo005
 */
#pragma once
#include <wx/wx.h>

class MyApp: public wxApp {
public:
	virtual bool OnInit();
};

DECLARE_APP(MyApp)
