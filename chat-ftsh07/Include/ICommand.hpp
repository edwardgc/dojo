/*
 * ICommand.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <string>
#include <memory>
#include "User.hpp"
using namespace std;

class ICommand
{
public:
    virtual void run(shared_ptr<User> p_user, string p_arg) = 0;
    virtual ~ICommand() = default;
};


