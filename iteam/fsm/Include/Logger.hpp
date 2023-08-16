/*
 * ILogger.hpp
 *
 *  Created on: 2017��8��10��
 *      Author: cguo005
 */
#pragma once
enum class StateId;

namespace fn
{

class Logger
{
public:
    virtual void printLogWhenEnterState(StateId) = 0;
    virtual void printLogWhenExitState(StateId) = 0;
    virtual ~Logger() = default;
};

} //namespace fn
