/*
 * IResource.hpp
 *
 *  Created on: 2017��8��21��
 *      Author: cguo005
 */

#pragma once

class IResource
{
public:
    virtual void read()=0;
    virtual void write()=0;
    virtual ~IResource() = default;
};


