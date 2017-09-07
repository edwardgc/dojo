/*
 * AccountingMock.hpp
 *
 *  Created on: 2017Äê8ÔÂ22ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <gmock/gmock.h>
#include <IAccounting.hpp>

class AccountingMock: public IAccounting
{
public:
    MOCK_METHOD1(account, bool(int));
};


