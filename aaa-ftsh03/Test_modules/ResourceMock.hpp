/*
 * ResourceMock.hpp
 *
 *  Created on: 2017��8��21��
 *      Author: cguo005
 */

#pragma once

#include <gmock/gmock.h>
#include "IResource.hpp"

class ResourceMock: public IResource
{
public:
    MOCK_METHOD0(read, void());
    MOCK_METHOD0(write, void());
};


