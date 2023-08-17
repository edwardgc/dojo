/**
 * Copyright (c) 2023 Nokia. All rights reserved.
 * This program contains proprietary information which is a trade secret
 * of Nokia and also is protected as an unpublished work under applicable
 * Copyright laws. Recipient is to retain this program in confidence and
 * is not permitted to use or make copies thereof other than as permitted
 * in a written agreement with Nokia.
 */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Fsm.hpp"
#include "Event.hpp"
#include "LightMock.hpp"
#include "LoggerMock.hpp"
#include "StateId.hpp"

using namespace std;
using namespace testing;

namespace fn
{
class FsmTest : public Test
{
public:
    LightMock m_light;
    LoggerMock m_logger;
    Fsm m_fsmTest = Fsm(m_light, m_logger);

};

TEST_F(FsmTest, handleEvent_LightOn)
{
    EXPECT_CALL(m_logger, printLogWhenExitState(StateId::OFF)).WillOnce(Return());
    EXPECT_CALL(m_light, turnOn()).WillOnce(Return());
    EXPECT_CALL(m_logger, printLogWhenEnterState(StateId::ON)).WillOnce(Return());
    m_fsmTest.handle(Event::SWITCH);

}

TEST_F(FsmTest, handleEvent_LightOff)
{
    m_fsmTest.handle(Event::SWITCH);
    EXPECT_CALL(m_logger, printLogWhenEnterState(StateId::OFF)).WillOnce(Return());
    EXPECT_CALL(m_light, turnOff()).WillOnce(Return());
    EXPECT_CALL(m_logger, printLogWhenExitState(StateId::ON)).WillOnce(Return());
    m_fsmTest.handle(Event::SWITCH);
}

TEST_F(FsmTest, handleEvent_LightOnOffOn)
{
    m_fsmTest.handle(Event::SWITCH);
    m_fsmTest.handle(Event::SWITCH);
    EXPECT_CALL(m_logger, printLogWhenExitState(StateId::OFF)).WillOnce(Return());
    EXPECT_CALL(m_light, turnOn()).WillOnce(Return());
    EXPECT_CALL(m_logger, printLogWhenEnterState(StateId::ON)).WillOnce(Return());
    m_fsmTest.handle(Event::SWITCH);
}

}
