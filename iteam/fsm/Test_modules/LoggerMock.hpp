/*
 * LoggerMock.hpp
 *
 *  Created on: 2017��8��10��
 *      Author: cguo005
 */
#pragma once
#include <gmock/gmock.h>
#include "Logger.hpp"


namespace fn
{

class LoggerMock : public Logger
{
public:
    MOCK_METHOD(void, printLogWhenEnterState, (StateId));
    MOCK_METHOD(void, printLogWhenExitState, (StateId));
};

} //namespace fn


