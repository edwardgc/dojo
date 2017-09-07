/*
 * Accounting.hpp
 *
 *  Created on: 2017��8��22��
 *      Author: cguo005
 */

#pragma once

class IAccounting
{
public:
    virtual bool account(int userId) = 0;
    virtual ~IAccounting() = default;
};


