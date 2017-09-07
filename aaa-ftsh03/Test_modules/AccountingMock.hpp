/*
 * AccountingMock.hpp
 *
 *  Created on: 2017��8��22��
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


