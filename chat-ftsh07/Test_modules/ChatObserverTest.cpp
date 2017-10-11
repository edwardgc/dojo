#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ChatObserver.hpp"
#include <memory>
#include "SessionMock.hpp"
#include "User.hpp"

using namespace std;
using namespace testing;
class ChatObserverTest : public Test
{
public:
    shared_ptr<SessionMock> sessionMock = make_shared<SessionMock>();
};

TEST_F(ChatObserverTest,addUser)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    string userName = "user0";
    EXPECT_CALL(*sessionMock, getName()).WillOnce(Return(userName));
    EXPECT_TRUE(l_ChatObserver.isUserExist(userName));

}

TEST_F(ChatObserverTest, firstUserShouldBeAdmin)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    EXPECT_EQ(Auth::ADMIN, l_ChatObserver.m_users[0]->auth);
}

TEST_F(ChatObserverTest, secondUserShouldNotBeAdmin)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    l_ChatObserver.onNewSession(sessionMock);
    EXPECT_EQ(Auth::ADMIN, l_ChatObserver.m_users[0]->auth);
    EXPECT_NE(Auth::ADMIN, l_ChatObserver.m_users[1]->auth);
}

TEST_F(ChatObserverTest, createRoom)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    l_ChatObserver.onReceive(sessionMock, "/create room1");
    EXPECT_EQ("room1", l_ChatObserver.m_rooms[0]->name);
}

TEST_F(ChatObserverTest, ignoreMessageWhenNoRoom)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    l_ChatObserver.onReceive(sessionMock, "create room1");
    EXPECT_TRUE(l_ChatObserver.m_rooms.empty());
}

TEST_F(ChatObserverTest, notCreateRoomIfWrongCommand)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    l_ChatObserver.onReceive(sessionMock, "/nick room1");
    EXPECT_TRUE(l_ChatObserver.m_rooms.empty());
}

TEST_F(ChatObserverTest, changeUserName)
{
    ChatObserver l_ChatObserver;
    l_ChatObserver.onNewSession(sessionMock);
    EXPECT_CALL(*sessionMock, setName("newName"));
    l_ChatObserver.onReceive(sessionMock, "/nick newName");
}
