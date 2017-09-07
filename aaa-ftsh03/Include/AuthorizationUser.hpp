/*
 * AuthorizationUser.hpp
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: cguo005
 */

#pragma once
#include "IAuthentication.hpp"
#include "IResource.hpp"

class IAccounting;

class AuthorizationUser:public IResource
{
public:
    AuthorizationUser(User p_user, IResource &p_resource, IAccounting &p_accounting)
        :m_user(p_user),
         m_resource(p_resource),
         m_accounting(p_accounting){}
    ~AuthorizationUser() = default;
    bool operator==(const AuthorizationUser &p_rhs) const
    {
        return m_user == p_rhs.m_user;
    }
    bool isAccountingAllowed();
    void read() override;
    void write() override;
private:
    User m_user;
    IResource &m_resource;
    IAccounting &m_accounting;
};




