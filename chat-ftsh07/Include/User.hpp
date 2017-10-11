#pragma once
#include <string>
#include "ISession.hpp"
#include <memory>
using namespace std;

enum class Auth
{
    NORMAL,
    ADMIN
};

class User
{
public:
    User(shared_ptr<ISession> p_session):session(p_session)
    {}
    shared_ptr<ISession> session;
    Auth auth = Auth::NORMAL;
};
