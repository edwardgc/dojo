#include <Main.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "gtest/gtest.h"
#include "Authorization.hpp"
#include "AuthenticationMock.hpp"
#include <exception>
#include "AuthorizationUser.hpp"
#include "AccountingMock.hpp"
#include "ResourceMock.hpp"

using namespace std;
using namespace ::testing;

class AuthorizationTestSuite: public Test
{
public:
    AuthenticationMock l_autMock;
    AccountingMock l_accMock;
    ResourceMock l_resMock;
    User l_user{784, ROLE::READER};

};

TEST_F(AuthorizationTestSuite, userIsAccepted)
{
    Authorization l_aut("TanShenqiang", "123456", l_autMock);
    EXPECT_CALL(l_autMock, login("TanShenqiang", "123456"));
    EXPECT_NO_THROW(l_aut.login());
}

TEST_F(AuthorizationTestSuite, passwordIsInvalid)
{
    Authorization l_aut("TanShenqiang", "123456", l_autMock);
    EXPECT_CALL(l_autMock, login("TanShenqiang", "123456")).WillOnce(Throw(invalid_argument("invalid password")));
    EXPECT_THROW(l_aut.login(), invalid_argument);
}

TEST_F(AuthorizationTestSuite, authorizationUserIsCreated)
{
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    Authorization l_aut("TanShenqiang", "123456", l_autMock);
    EXPECT_CALL(l_autMock, login("TanShenqiang", "123456")).WillOnce(Return(l_user));
    EXPECT_EQ(l_authorizationUser, *dynamic_cast<AuthorizationUser *>(l_aut.create(l_resMock, l_accMock)));
}

TEST_F(AuthorizationTestSuite, accountOfAuthorizationUserIsValid)
{
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    EXPECT_CALL(l_accMock, account(l_user.userId)).WillOnce(Return(true));
    EXPECT_TRUE(l_authorizationUser.isAccountingAllowed());
}

TEST_F(AuthorizationTestSuite, accountOfAuthorizationUserIsInvalid)
{
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    EXPECT_CALL(l_accMock, account(l_user.userId)).WillOnce(Return(false));
    EXPECT_FALSE(l_authorizationUser.isAccountingAllowed());
}

TEST_F(AuthorizationTestSuite, ValidReaderIsJustAllowedToRead)
{
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    EXPECT_CALL(l_accMock, account(l_user.userId)).WillOnce(Return(true));
    EXPECT_CALL(l_resMock, read());
    l_authorizationUser.read();
}

TEST_F(AuthorizationTestSuite, AuthorIsAllowedToWrite)
{
    l_user = {1, ROLE::AUTHOR};
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    EXPECT_CALL(l_resMock, write());
    l_authorizationUser.write();
}

TEST_F(AuthorizationTestSuite, ReaderIsNotAllowedToWrite)
{
    AuthorizationUser l_authorizationUser{l_user, l_resMock, l_accMock};
    EXPECT_THROW(l_authorizationUser.write(), logic_error);

}
