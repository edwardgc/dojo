/*
 * FsmBase.hpp
 *
 *  Created on: 2017Äê8ÔÂ9ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "State.hpp"

class FsmBase
{
public:
    void transitionToState(State& p_newState)
    {
        m_currentState = &p_newState;
    }
    void forwardEvent(Event p_event)
    {
        m_currentState->handle(p_event);
    }
    ~FsmBase() = default;
protected:
    State* m_currentState;
};


