/*
 * Room.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <string>
#include <vector>
#include "User.hpp"

class Room
{
public:
    Room(std::string p_name):name(p_name)
    {}
    std::string name;
    shared_ptr<User> op;
    std::vector<shared_ptr<User>> members;
};


