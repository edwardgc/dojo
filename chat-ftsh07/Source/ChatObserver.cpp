/*
 * ChatObserver.cpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */


#include "ChatObserver.hpp"
#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;


void ChatObserver::onNewSession(std::shared_ptr<ISession> p_session)
{
    auto l_user = make_shared<User>(p_session);
    if(m_users.empty())
    {
        l_user->auth = Auth::ADMIN;
    }
    m_users.push_back(l_user);
}

void ChatObserver::onReceive(std::shared_ptr<ISession> p_session, std::string message)
{
    auto l_user = findUser(p_session);
    if((not message.empty()) and message[0] == '/' and l_user)
    {
        m_invoker.invoke(l_user, message);
    }
}

void ChatObserver::onSessionClose(std::shared_ptr<ISession>)
{

}

bool ChatObserver::isUserExist(string& p_userName)
{
    for(auto l_user:m_users)
    {
        if(p_userName == l_user->session->getName())
            return true;
    }
    return false;
}

shared_ptr<User> ChatObserver::findUser(const shared_ptr<ISession>& p_session)
{
    for (auto it : m_users)
    {
        if (p_session == it->session)
        {
            return it;
        }
    }
    return nullptr;
}
