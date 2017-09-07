#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Fsm.hpp"
#include "LightMock.hpp"

using namespace std;
using namespace testing;

struct FsmTestSuite : Test
{
    FsmTestSuite()
    {
    }
protected:
    StrictMock<LightMock> m_light{};
};

TEST_F(FsmTestSuite, turnOnLight)
{
    Fsm fsm { m_light };
    EXPECT_CALL(m_light, turnOn());

    fsm.forwardEvent(Event::SWITCH);
}

TEST_F(FsmTestSuite, switchTwiceWhenOff)
{
    Fsm fsm { m_light };
    EXPECT_CALL(m_light, turnOn());
    fsm.forwardEvent(Event::SWITCH);

    EXPECT_CALL(m_light, turnOff());
    fsm.forwardEvent(Event::SWITCH);
}

TEST_F(FsmTestSuite, switchTwiceWhenOn)
{
    Fsm fsm { m_light };
    fsm.transitionToState(fsm.stateOn);
    EXPECT_CALL(m_light, turnOff());
    fsm.forwardEvent(Event::SWITCH);

    EXPECT_CALL(m_light, turnOn());
    fsm.forwardEvent(Event::SWITCH);
}
