#pragma once

#include <memory>
#include <vector>
#include "IChatObserver.hpp"
#include "User.hpp"
#include "Room.hpp"
#include "Invoker.hpp"

using namespace std;

class ChatObserver : public IChatObserver
{
public:
    ChatObserver(): m_users(), m_rooms(), m_invoker(m_users, m_rooms)
    {}
    void onNewSession(std::shared_ptr<ISession>) override;
    void onReceive(std::shared_ptr<ISession>, std::string message) override;
    void onSessionClose(std::shared_ptr<ISession>) override;
    bool isUserExist(string&);

    vector<shared_ptr<User>> m_users;
    vector<shared_ptr<Room>> m_rooms;
    Invoker m_invoker;

private:
    shared_ptr<User> findUser(const shared_ptr<ISession>& p_session);
};
