/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "IWatchObserver.hpp"

class GuiObserver : public IWatchObserver
{
public:
    void onSwitchClick();
    void onUpClick();
    void onDownClick();
    std::string onSecond();
};



