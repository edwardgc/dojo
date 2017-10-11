/*
 * Nick.cpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#include "Nick.hpp"

void Nick::run(shared_ptr<User> p_user, string p_arg)
{
    p_user->session->setName(p_arg);
}


