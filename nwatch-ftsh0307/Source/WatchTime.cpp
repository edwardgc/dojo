/*
 * WatchTime.cpp
 *
 *  Created on: 2017Äê9ÔÂ13ÈÕ
 *      Author: cguo005
 */

#include "ITime.hpp"
#include <ctime>

std::string WatchTime::getCurrentTime()
{
    auto l_tm = std::time(NULL);
    auto l_time = std::localtime(&l_tm);
    auto l_minute = l_time->tm_min;
    auto l_sec = l_time->tm_sec;

    return std::to_string(l_minute) + " : " + std::to_string(l_sec);
}




