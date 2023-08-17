/*
 * State.hpp
 *
 *  Created on: 2017��8��10��
 *      Author: cguo005
 */
#pragma once
#include <ostream>

namespace fn
{

enum class StateId : int
{
    ON,
    OFF,
};


} //namespace fn

std::ostream& operator<<(std::ostream &os, const fn::StateId &id);
