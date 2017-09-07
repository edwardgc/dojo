/*
 * ILight.hpp
 *
 *  Created on: 2017Äê8ÔÂ7ÈÕ
 *      Author: cguo005
 */

#pragma once

class ILight
{
public:
    virtual void turnOn() = 0;
    virtual void turnHalfOn() = 0;
    virtual void turnOff() = 0;
    virtual ~ILight() = default;
};


