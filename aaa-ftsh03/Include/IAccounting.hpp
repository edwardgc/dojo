/*
 * Accounting.hpp
 *
 *  Created on: 2017Äê8ÔÂ22ÈÕ
 *      Author: cguo005
 */

#pragma once

class IAccounting
{
public:
    virtual bool account(int userId) = 0;
    virtual ~IAccounting() = default;
};


