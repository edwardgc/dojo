/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "IWatchObserver.hpp"
#include <Fsm.hpp>

class GuiObserver : public IWatchObserver
{
public:
    GuiObserver(shared_ptr<ITime> p_time);
    void onSwitchClick();
    void onUpClick();
    void onDownClick();
    std::string onSecond();
    Fsm m_fsm;
};



