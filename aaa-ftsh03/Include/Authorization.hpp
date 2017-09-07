/*
 * Authorization.hpp
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: cguo005
 */

#pragma once
#include "IAuthentication.hpp"
#include "AuthorizationUser.hpp"
class User;

class Authorization
{
public:
    Authorization(const std::string& p_username, const std::string& p_password,
                  IAuthentication& p_authentication)
        : m_username(p_username),
          m_password(p_password),
          m_authentication(p_authentication){}
    virtual ~Authorization() = default;
    User login();
    IResource* create(IResource &p_resource, IAccounting &p_accounting);

private:
    std::string m_username;
    std::string m_password;
    IAuthentication& m_authentication;
};




