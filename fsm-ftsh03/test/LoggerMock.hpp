/*
 * LoggerMock.hpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */
#pragma once
#include <gmock/gmock.h>
#include "ILogger.hpp"

class LoggerMock : public ILogger
{
public:
    MOCK_METHOD1(printLogWhenEnterState, void(STATE_ID));
    MOCK_METHOD1(printLogWhenExitState, void(STATE_ID));
};



