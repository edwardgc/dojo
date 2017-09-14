#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Fsm.hpp"
#include "State.hpp"
#include "GuiObserver.hpp"
#include "TimeMock.hpp"
using namespace std;
using namespace testing;

struct FsmTestSuite : Test
{
    FsmTestSuite()
    {
    }
    shared_ptr<TimeMock> l_timeMock = make_shared<TimeMock>();
    Fsm l_testObj{l_timeMock};
    GuiObserver l_testGuiOb{l_timeMock};
};

TEST_F(FsmTestSuite, turnStopWatchToWatch)
{
    l_testObj.processEvent(EVENT::SWITCH_EVENT);

    EXPECT_EQ(STATE_ID::STATE_WATCH, l_testObj.getCurrentState()->getStateId());
}

TEST_F(FsmTestSuite, turnWatchToStopWatch)
{
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
    EXPECT_EQ(STATE_ID::STATE_WATCH, l_testObj.getCurrentState()->getStateId());
    l_testObj.processEvent(EVENT::SWITCH_EVENT);
    EXPECT_EQ(STATE_ID::STATE_STOPWATCH, l_testObj.getCurrentState()->getStateId());
}

TEST_F(FsmTestSuite, testInitOnSecond)
{

    EXPECT_EQ("0", l_testGuiOb.onSecond());
}

TEST_F(FsmTestSuite, testOneUpClickStartStopWatch)
{
    l_testGuiOb.onUpClick();
    EXPECT_EQ("1", l_testGuiOb.onSecond());
    EXPECT_EQ("2", l_testGuiOb.onSecond());
}

TEST_F(FsmTestSuite, testCountNotChangeAfterTwoUpClickInStopWatch)
{
    l_testGuiOb.onUpClick();
    EXPECT_EQ("1", l_testGuiOb.onSecond());
    EXPECT_EQ("2", l_testGuiOb.onSecond());
    l_testGuiOb.onUpClick();
    EXPECT_EQ("2", l_testGuiOb.onSecond());
    EXPECT_EQ("2", l_testGuiOb.onSecond());
}

TEST_F(FsmTestSuite, testCountClearAfterDownClickInStopWatch)
{
    l_testGuiOb.onUpClick();
    EXPECT_EQ("1", l_testGuiOb.onSecond());
    EXPECT_EQ("2", l_testGuiOb.onSecond());
    l_testGuiOb.onDownClick();
    EXPECT_EQ("0", l_testGuiOb.onSecond());
    EXPECT_EQ("0", l_testGuiOb.onSecond());
}

TEST_F(FsmTestSuite, testShowTimeOnWatch)
{
    string l_string = "200";
    EXPECT_CALL(*l_timeMock, getCurrentTime()).WillRepeatedly(Return(l_string));
    l_testGuiOb.onSwitchClick();
    EXPECT_EQ(l_string, l_testGuiOb.onSecond());
}

TEST_F(FsmTestSuite, testOnSwitchClick)
{
    l_testGuiOb.onSwitchClick();
    EXPECT_EQ(STATE_ID::STATE_WATCH, l_testGuiOb.m_fsm.getCurrentState()->getStateId());
}


