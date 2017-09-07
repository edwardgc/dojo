#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Fsm.hpp"
#include "LightMock.hpp"
#include "LoggerMock.hpp"
#include "State.hpp"

using namespace std;
using namespace testing;

struct FsmTestSuite : Test
{
    FsmTestSuite()
    {
    }
protected:
    StrictMock<LightMock> m_light{};
    NiceMock<LoggerMock> m_logger{};
};

TEST_F(FsmTestSuite, turnOnHalfLight)
{
    EXPECT_CALL(m_light, turnHalfOn());
    Fsm l_testObj{m_light, m_logger};
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
}

TEST_F(FsmTestSuite, turnOnLight)
{
    Fsm l_testObj{m_light, m_logger};
    EXPECT_CALL(m_light, turnHalfOn());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);

    EXPECT_CALL(m_light, turnOn());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
}

TEST_F(FsmTestSuite, turnOffLight)
{
    Fsm l_testObj{m_light, m_logger};
    EXPECT_CALL(m_light, turnHalfOn());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);

    EXPECT_CALL(m_light, turnOn());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);

    EXPECT_CALL(m_light, turnOff());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
}

TEST_F(FsmTestSuite, shouldPrintLogWhenEnterAndExitState)
{
    StrictMock<LoggerMock> l_logger{};
    EXPECT_CALL(m_light, turnHalfOn());
    EXPECT_CALL(l_logger, printLogWhenEnterState(STATE_ID::STATE_HALF_ON));
    EXPECT_CALL(l_logger, printLogWhenExitState(STATE_ID::STATE_OFF));

    Fsm l_testObj{m_light, l_logger};
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
}

