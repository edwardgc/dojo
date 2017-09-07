/*
 * Fsm.cpp
 *
 *  Created on: 2017��8��7��
 *      Author: cguo005
 */

#include "Fsm.hpp"

using namespace std;

Fsm::Fsm(ILight& p_light) : light(p_light),
                            stateOn(this, light),
                            stateOff(this, light)

{
    m_currentState = &stateOff;
}
