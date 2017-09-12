/*
 * WatchObserver.cpp
 *
 *  Created on: 2017Äê9ÔÂ12ÈÕ
 *      Author: cguo005
 */

#include <iostream>
#include "WatchObserver.hpp"

using namespace std;

void WatchObserver::onSwitchClick()
{
	cout << "switch clicked" << endl;
}

void WatchObserver::onUpClick()
{
	cout << "up clicked" << endl;
}

void WatchObserver::onDownClick()
{
	cout << "down clicked" << endl;
}

std::string WatchObserver::onSecond()
{
	cout << "one second timeout" << endl;
	return "";
}


