#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ChatObserver.hpp"
#include "SessionMock.hpp"

using namespace std;
using namespace testing;

struct ChatRoomTestSuite : public Test
{
    shared_ptr<SessionMock> sessionMock = make_shared<SessionMock>();
    shared_ptr<SessionMock> adminSessionMock = make_shared<SessionMock>();
    ChatObserver chatObserver;
    void SetUp()
    {
        chatObserver.onNewSession(adminSessionMock);
        chatObserver.onNewSession(sessionMock);
        chatObserver.onReceive(adminSessionMock, "/create room1");
        EXPECT_CALL(*sessionMock,getName()).WillRepeatedly(Return("User1") );
    }
};

TEST_F(ChatRoomTestSuite, checkIsAdmin)
{
    EXPECT_TRUE(chatObserver.isAdmin(adminSessionMock));
}

TEST_F(ChatRoomTestSuite, checkIsNotAdmin)
{
    EXPECT_FALSE(chatObserver.isAdmin(sessionMock));
}

TEST_F(ChatRoomTestSuite, checkCreateChatRoom)
{
    EXPECT_EQ("room1\n", chatObserver.listRoom());
}

TEST_F(ChatRoomTestSuite, checkUserJoinChatRoom)
{
    chatObserver.onReceive(sessionMock, "/join room1");
    EXPECT_EQ("User1\n", chatObserver.listUser("room1"));
}
