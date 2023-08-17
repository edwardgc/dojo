/**
 * Copyright (c) 2023 Nokia. All rights reserved.
 * This program contains proprietary information which is a trade secret
 * of Nokia and also is protected as an unpublished work under applicable
 * Copyright laws. Recipient is to retain this program in confidence and
 * is not permitted to use or make copies thereof other than as permitted
 * in a written agreement with Nokia.
 */

#pragma once
#include "Event.hpp"
#include "StateId.hpp"
#include "Fsm.hpp"

namespace fn
{

class State
{
public:
    virtual void trigger(Event event) = 0;
    virtual ~State() = default;
};

class StateOn : public State
{
public:
    StateOn(Fsm &fsm);
    void trigger(Event event) override;

private:
    Fsm &m_fsm;

};

class StateOff : public State
{
public:
    StateOff(Fsm &fsm);
    void trigger(Event event) override;

private:
    Fsm &m_fsm;
};

}



