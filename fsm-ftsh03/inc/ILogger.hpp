/*
 * ILogger.hpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */
#pragma once
enum class STATE_ID;

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void printLogWhenEnterState(STATE_ID) = 0;
    virtual void printLogWhenExitState(STATE_ID) = 0;
};


