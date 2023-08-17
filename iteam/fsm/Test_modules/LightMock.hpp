#pragma once
#include <gmock/gmock.h>
#include "Light.hpp"

namespace fn
{

class LightMock : public Light
{
public:
    MOCK_METHOD(void, turnOn, ());
    MOCK_METHOD(void, turnOff, ());
};

} //namespace fn
