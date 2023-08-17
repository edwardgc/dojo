/**
 * Copyright (c) 2023 Nokia. All rights reserved.
 * This program contains proprietary information which is a trade secret
 * of Nokia and also is protected as an unpublished work under applicable
 * Copyright laws. Recipient is to retain this program in confidence and
 * is not permitted to use or make copies thereof other than as permitted
 * in a written agreement with Nokia.
 */
#pragma once

#include <memory>
#include <map>
#include "StateId.hpp"
#include "Event.hpp"
#include "Logger.hpp"

namespace fn
{

class Light;
class State;

class Fsm
{
public:
    Fsm(Light& m_light,Logger &m_logger);
    void handle(Event event);
    void turnOn();
    void turnOff();
    void transmit(StateId stateId);

private:
    Light &m_light;
    Logger &m_logger;
    StateId m_stateId;
    std::map<StateId, std::shared_ptr<State>> mp;
};

} /* namespace hwa */
