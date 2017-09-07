/*
 * State.cpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */
#include "State.hpp"

State::State(STATE_ID p_StateID ,ILogger &p_logger):m_id(p_StateID),
                                                    m_logger(p_logger){}

void State::addTransition(EVENT p_event, std::function<void()> p_fun)
{
    m_transitionMap.insert({p_event, p_fun});
}

void State::handleEvent(EVENT p_event)
{
    m_transitionMap[p_event]();
}

void State::enter()
{
    m_logger.printLogWhenEnterState(m_id);
}

void State::exit()
{
    m_logger.printLogWhenExitState(m_id);
}
