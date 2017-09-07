/*
 * AuthorizationUser.cpp
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: cguo005
 */
#include "AuthorizationUser.hpp"
#include "IAccounting.hpp"
#include "IResource.hpp"
#include <stdexcept>

bool AuthorizationUser::isAccountingAllowed()
{
    return m_accounting.account(m_user.userId);
}

void AuthorizationUser::read()
{
    if(isAccountingAllowed())
    {
        m_resource.read();
    }
}

void AuthorizationUser::write()
{
    if(ROLE::AUTHOR == m_user.role)
    {
        m_resource.write();
    }
    else
    {
        throw std::logic_error{"You have no right to write!"};
    }

}
