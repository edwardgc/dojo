/*
 * Authentication.hpp
 *
 *  Created on: 2017��8��21��
 *      Author: cguo005
 */

#pragma once

#include <string>
#include "Authorization.hpp"
#include <memory>


class IAuthentication
{
public:
    virtual std::shared_ptr<User> login(const std::string& user, const std::string& name) = 0;
    virtual ~IAuthentication() = default;
};


