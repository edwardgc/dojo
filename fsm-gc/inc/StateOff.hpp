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

class StateOff : public State
{
public:
    StateOff(Fsm* p_fsm, ILight& p_light);
    void handleSwitch(const Event& p_event);
    ~StateOff() = default;
private:
    Fsm* m_fsm;
    ILight& m_light;
};
