/*
 * Authorization.hpp
 *
 *  Created on: 2017��8��21��
 *      Author: cguo005
 */

#pragma once

#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include "IResource.hpp"

class IAuthentication;

class InvalidUser : std::logic_error
{
public:
    InvalidUser() : std::logic_error("InvalidUser")
        {}
};

class WriteForbidden : std::exception
{
public:
    WriteForbidden() : std::exception()
        {}
};


enum EUserRole
{
    E_READER,
    E_AUTHOR
};

enum EUserPermission
{
    E_READONLY,
    E_WRITE8READ
};

struct User
{
   int id;
   std::string name;
   std::string passwd;
   EUserRole role;
   double account;
};

class CAuthorizationServer
{
public:
    CAuthorizationServer(std::shared_ptr<IAuthentication> p_Authentication,
                             std::shared_ptr<IResource> p_Resource )
    {
        m_Authentication = p_Authentication;
        m_Resource = p_Resource;
    }
    ~CAuthorizationServer() = default;

     EUserPermission getPermission(const std::string name,
                                 const std::string passwd);
     std::shared_ptr<IResource> getResource(const std::string name,
                                 const std::string passwd);

private:

    std::vector<User> m_userTable;
    std::shared_ptr<IAuthentication> m_Authentication;
    std::shared_ptr<IResource> m_Resource;
};



