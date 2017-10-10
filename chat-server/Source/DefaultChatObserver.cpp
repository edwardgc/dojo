/*
 * DefaultChatObserver.cpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#include "DefaultChatObserver.hpp"
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

void DefaultChatObserver::onNewSession(std::shared_ptr<ISession> user)
{
    m_users.insert(user);
    for_each(m_recentMsgs.begin(), m_recentMsgs.end(),
            bind(&ISession::deliver, user, placeholders::_1));
}

void DefaultChatObserver::onReceive(std::shared_ptr<ISession> user, std::string message)
{
    cout << "receive " << message << endl;
    message = "[" + user->getName() + "] " + message;
    m_recentMsgs.push_back(message);
    while (m_recentMsgs.size() > max_recent_msgs)
        m_recentMsgs.pop_front();

    for_each(m_users.begin(), m_users.end(),
            bind(&ISession::deliver, placeholders::_1, message)); // 12
}

void DefaultChatObserver::onSessionClose(std::shared_ptr<ISession> user)
{
    m_users.erase(user);
}
