/*
 * Invoker.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <string>
#include <memory>
#include <map>
#include "ICommand.hpp"
#include "Create.hpp"
#include "User.hpp"
#include "Room.hpp"
#include "Nick.hpp"
using namespace std;

class User;
class Invoker
{
public:
    Invoker(vector<shared_ptr<User>>& p_users, vector<shared_ptr<Room>>& p_rooms):
        m_users(p_users), m_rooms(p_rooms)
    {}
    void invoke(shared_ptr<User> p_user, string message);
private:
    vector<shared_ptr<User>>& m_users;
    vector<shared_ptr<Room>>& m_rooms;
    map<string, shared_ptr<ICommand>> m_commands {
            {"create", make_shared<Create>(m_rooms)},
            {"nick", make_shared<Nick>()}};
};


