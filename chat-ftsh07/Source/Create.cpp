/*
 * Create.cpp
 *
 *  Created on: 2017��10��11��
 *      Author: cguo005
 */

#include "Create.hpp"

void Create::run(shared_ptr<User> p_user, string p_arg)
{
    if(Auth::ADMIN == p_user->auth)
    {
        m_rooms.push_back(make_shared<Room>(p_arg));
    }
}

