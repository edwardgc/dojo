/*
 * Room.hpp
 *
 *  Created on: 2017Äê10ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <string>
#include <vector>
#include <memory>
#include "ISession.hpp"

class Room : public ISession
{
public:
    Room(const std::string&);
    void setName(const std::string&);
    std::string getName()const;
    void deliver(const std::string&);
    void join(std::shared_ptr<ISession>);
    std::string listUsers();
private:
    std::vector<std::shared_ptr<ISession>> m_users;
    std::string m_roomName;

};



