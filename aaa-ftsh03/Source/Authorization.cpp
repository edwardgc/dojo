/*
 * Authorization.cpp
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: cguo005
 */

#include "Authorization.hpp"

User Authorization::login()
{
    return m_authentication.login(m_username, m_password);
}

IResource* Authorization::create(IResource &p_resource, IAccounting &p_accounting)
{
     AuthorizationUser *l_authorizationUser = new AuthorizationUser(login(), p_resource, p_accounting);
     return l_authorizationUser;
}


