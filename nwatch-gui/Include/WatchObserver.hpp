/*
 * WatchObserver.hpp
 *
 *  Created on: 2017Äê9ÔÂ12ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "IWatchObserver.hpp"

class WatchObserver : public IWatchObserver
{
public:
	void onSwitchClick() override;
	void onUpClick() override;
	void onDownClick() override;
	std::string onSecond() override;
};


