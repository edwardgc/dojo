/*
 * StateOn.cpp
 *
 *  Created on: 2017Äê8ÔÂ9ÈÕ
 *      Author: cguo005
 */

#include "StateOn.hpp"
#include "Fsm.hpp"
#include <map>
#include <functional>

using namespace std;

StateOn::StateOn(Fsm* p_fsm, ILight& p_light) : State(StateId::ON), m_fsm(p_fsm), m_light(p_light)
{
    m_transitions.insert({Event::SWITCH, bind(&StateOn::handleSwitch, this, placeholders::_1)});
}

void StateOn::handleSwitch(const Event& p_event)
{
    m_light.turnOff();
    m_fsm->transitionToState(m_fsm->stateOff);
}

