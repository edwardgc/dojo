/*
 * Main.hpp
 *
 *  Created on: 2017��8��18��
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



