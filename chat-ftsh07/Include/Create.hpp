/*
 * Create.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "ICommand.hpp"
#include "Room.hpp"

class Create : public ICommand
{
public:
    Create(vector<shared_ptr<Room>>& p_rooms):m_rooms(p_rooms){}
    void run(shared_ptr<User> p_user, string p_arg) override;
private:
    vector<shared_ptr<Room>>& m_rooms;
};


