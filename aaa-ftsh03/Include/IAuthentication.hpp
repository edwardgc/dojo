/*
 * Authentication.hpp
 *
 *  Created on: 2017Äê8ÔÂ21ÈÕ
 *      Author: cguo005
 */

#pragma once

#include <string>
#include <memory>

enum class ROLE
{
    READER,
    AUTHOR
};

struct User
{
    int userId;
    ROLE role;
    bool operator == (const User &p_rhs) const
    {
         return (userId == p_rhs.userId) && (role == p_rhs.role);
    }
};

class IAuthentication
{
public:
    virtual User login(const std::string& user, const std::string& name) = 0;
    virtual ~IAuthentication() = default;
};


