/*
 * ITime.hpp
 *
 *  Created on: 2017Äê9ÔÂ13ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <string>

class ITime
{
public:
    virtual std::string getCurrentTime() = 0;
    virtual ~ITime() = default;
};

class WatchTime : public ITime
{
public:
    std::string getCurrentTime();
};



