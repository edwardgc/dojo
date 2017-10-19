/*
 * DefaultChatObserver.cpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#include "ChatObserver.hpp"
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

ChatObserver::ChatObserver()
{
    comandAction = {{"create", createRoom},{"join", joinRoom}};
}

void ChatObserver::onNewSession(std::shared_ptr<ISession> user)
{
    m_users.insert(user);
    if (not admin)
    {
        admin = user;
    }
}

bool ChatObserver::isAdmin(std::shared_ptr<ISession> user)
{
    return user == admin;
}

void ChatObserver::createRoom(std::shared_ptr<ISession> user, std::string arg)
{
    if (admin != user)
    {
        return;
    }
    shared_ptr<Room> chatRoom = make_shared<Room>(arg);
    m_rooms.push_back(chatRoom);
}

void ChatObserver::joinRoom(std::shared_ptr<ISession> user, std::string arg)
{
    auto room = find_if(m_rooms.begin(),m_rooms.end(),[&](auto room){return arg==room->getName();});
    if(room == m_rooms.end())
    {
        cout<<"ERROR:room is not exist"<<endl;
        return;
    }
    (*room)->join(user);
}

void ChatObserver::onReceive(std::shared_ptr<ISession> user, std::string message)
{
    cout << "receive " << message << endl;
    if ('/' == message[0])
    {
        string command = message.substr(1, message.find(' ') - 1);
        string arg = message.substr(message.find(' ') + 1);
        cout << command << "," << arg << endl;

        (this->*comandAction[command])(user,arg);
    }
}

void ChatObserver::onSessionClose(std::shared_ptr<ISession> user)
{
//    m_users.erase(user);
}

string ChatObserver::listRoom()
{
    string str;
    for_each(m_rooms.begin(), m_rooms.end(), [&](auto room)
    {   str += room->getName() + "\n";});
    return str;
}
string ChatObserver::listUser(const std::string& p_room)
{
    auto room = find_if(m_rooms.begin(),m_rooms.end(),[&](auto room){return p_room==room->getName();});
    return (*room)->listUsers();
}

