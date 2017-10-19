/*
 * SessionMock.hpp
 *
 *  Created on: 2017��10��18��
 *      Author: cguo005
 */
#pragma once
#include "ISession.hpp"

class SessionMock : public ISession
{
public:
    MOCK_METHOD1(deliver, void(const std::string&));
    MOCK_CONST_METHOD0(getName,std::string());
    MOCK_METHOD1(setName, void(const std::string&));
};






