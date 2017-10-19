/*
 * DefaultChatObserver.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <set>
#include <vector>
#include <deque>
#include <string>
#include "IChatObserver.hpp"
#include "ChatMessage.hpp"
#include "Room.hpp"
#include <map>

class ChatObserver : public IChatObserver
{
public:
    ChatObserver();
    void onNewSession(std::shared_ptr<ISession>) override;
    void onReceive(std::shared_ptr<ISession>, std::string message) override;
    void onSessionClose(std::shared_ptr<ISession>) override;
    bool isAdmin(std::shared_ptr<ISession>);
    std::string listRoom();
    std::string listUser(const std::string&);
    void createRoom(std::shared_ptr<ISession>, std::string message);
    void joinRoom(std::shared_ptr<ISession>, std::string message);
private:
    std::shared_ptr<ISession> admin = nullptr;
    std::set<std::shared_ptr<ISession>> m_users;
    std::vector<std::shared_ptr<Room>> m_rooms;
    std::map<std::string, void(ChatObserver::*)(std::shared_ptr<ISession>, std::string)> comandAction;

};




