/*
 * FSM.hpp
 *
 *  Created on: 2017Äê8ÔÂ7ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "FsmBase.hpp"
#include "ILight.hpp"
#include "StateOn.hpp"
#include "StateOff.hpp"

class Fsm : public FsmBase
{
public:
    Fsm(ILight& p_light);
    ILight& light;
    StateOn stateOn;
    StateOff stateOff;
};



