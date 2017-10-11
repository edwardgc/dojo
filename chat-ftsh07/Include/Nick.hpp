/*
 * Nick.hpp
 *
 *  Created on: 2017��10��11��
 *      Author: cguo005
 */

#pragma once

#include "ICommand.hpp"
#include "User.hpp"

class Nick : public ICommand
{
public:
    void run(shared_ptr<User> p_user, string p_arg) override;
};



