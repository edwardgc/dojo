/*
 * StateOn.hpp
 *
 *  Created on: 2017Äê8ÔÂ9ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "State.hpp"

class Fsm;
class ILight;

using namespace std;

class StateOn : public State
{
public:
    StateOn(Fsm* p_fsm, ILight& p_light);
    void handleSwitch(const Event& p_event);
    ~StateOn() = default;
private:
    Fsm* m_fsm;
    ILight& m_light;
};
