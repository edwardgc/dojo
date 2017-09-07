/*
 * IState.hpp
 *
 *  Created on: 2017��8��7��
 *      Author: cguo005
 */

#pragma once

#include "Event.hpp"

class IState
{
public:
    virtual void handle(Event p_event) = 0;
    virtual ~IState() = default;
};

