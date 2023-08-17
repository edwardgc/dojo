/**
 * Copyright (c) 2023 Nokia. All rights reserved.
 * This program contains proprietary information which is a trade secret
 * of Nokia and also is protected as an unpublished work under applicable
 * Copyright laws. Recipient is to retain this program in confidence and
 * is not permitted to use or make copies thereof other than as permitted
 * in a written agreement with Nokia.
 */

#include "State.hpp"

namespace fn
{

StateOn::StateOn(Fsm &fsm)
        : m_fsm(fsm)
{

}

void StateOn::trigger(Event event)
{
    m_fsm.turnOff();
    m_fsm.transmit(StateId::OFF);
}

StateOff::StateOff(Fsm &fsm)
        : m_fsm(fsm)
{

}

void StateOff::trigger(Event event)
{

    m_fsm.turnOn();
    m_fsm.transmit(StateId::ON);
}

}

std::ostream& operator<<(std::ostream &os, const fn::StateId &id)
{
    switch (id)
    {
        case fn::StateId::ON:
            os << "ON";
            return os;
        case fn::StateId::OFF:
            os << "OFF";
            return os;
        default:
            os << "ALL";
            return os;
    }
}
