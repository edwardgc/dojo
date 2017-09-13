/*
 * TimeMock.hpp
 *
 *  Created on: 2017��9��13��
 *      Author: cguo005
 */

#pragma once
#include "ITime.hpp"
#include <gmock/gmock.h>
class TimeMock : public ITime
{
public:
    MOCK_METHOD0(getCurrentTime, std::string());

};


