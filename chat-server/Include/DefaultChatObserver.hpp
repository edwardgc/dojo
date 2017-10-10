/*
 * DefaultChatObserver.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <set>
#include <deque>
#include "IChatObserver.hpp"
#include "ChatMessage.hpp"

class DefaultChatObserver : public IChatObserver
{
public:
    void onNewSession(std::shared_ptr<ISession>) override;
    void onReceive(std::shared_ptr<ISession>, std::string message) override;
    void onSessionClose(std::shared_ptr<ISession>) override;
private:
    std::set<std::shared_ptr<ISession>> m_users;
    static const int max_recent_msgs = 100;
    std::deque<std::string> m_recentMsgs;
};

