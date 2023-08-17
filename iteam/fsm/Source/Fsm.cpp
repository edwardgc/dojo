/**
 * Copyright (c) 2023 Nokia. All rights reserved.
 * This program contains proprietary information which is a trade secret
 * of Nokia and also is protected as an unpublished work under applicable
 * Copyright laws. Recipient is to retain this program in confidence and
 * is not permitted to use or make copies thereof other than as permitted
 * in a written agreement with Nokia.
 */
#include "Fsm.hpp"
#include "StateId.hpp"
#include "Light.hpp"
#include "State.hpp"
using namespace std;
namespace fn
{

Fsm::Fsm(Light &light, Logger &logger)
        : m_light(light), m_logger(logger),m_stateId(StateId::OFF)
{
    mp[StateId::ON] = make_shared<StateOn>(*this);
    mp[StateId::OFF] = make_shared<StateOff>(*this);
}

void Fsm::handle(Event event)
{
    mp[m_stateId] -> trigger(event);
}

void Fsm::turnOn()
{
    m_light.turnOn();
}

void Fsm::turnOff()
{
    m_light.turnOff();
}

void Fsm::transmit(StateId stateId)
{
    m_logger.printLogWhenExitState(m_stateId);
    m_stateId = stateId;
    m_logger.printLogWhenEnterState(m_stateId);
}

}

