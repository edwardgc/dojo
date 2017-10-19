/*
 * Room.cpp
 *
 *  Created on: 2017Äê10ÔÂ18ÈÕ
 *      Author: cguo005
 */
#include "Room.hpp"
#include <algorithm>
using namespace std;

Room::Room(const string& p_roomName) : m_roomName(p_roomName)
{

}

void Room::setName(const std::string& p_roomName)
{
    m_roomName = p_roomName;
}

string Room::getName()const
{
    return m_roomName;
}

void Room::deliver(const std::string&)
{

}
void Room::join(std::shared_ptr<ISession> p_user)
{
    m_users.push_back(p_user);
}
std::string Room::listUsers()
{
    string l_users;
    for_each(m_users.begin(),m_users.end(),[&](shared_ptr<ISession> user){l_users+=user->getName()+"\n";});
    return l_users;
}

