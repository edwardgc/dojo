/*
 * StateOff.cpp
 *
 *  Created on: 2017Äê8ÔÂ9ÈÕ
 *      Author: cguo005
 */

#include "StateOff.hpp"
#include "Fsm.hpp"
#include <map>
#include <functional>

using namespace std;

StateOff::StateOff(Fsm* p_fsm, ILight& p_light) : State(StateId::OFF), m_fsm(p_fsm), m_light(p_light)
{
    m_transitions.insert({Event::SWITCH, bind(&StateOff::handleSwitch, this, placeholders::_1)});
}

void StateOff::handleSwitch(const Event& p_event)
{
    m_light.turnOn();
    m_fsm->transitionToState(m_fsm->stateOn);
}



