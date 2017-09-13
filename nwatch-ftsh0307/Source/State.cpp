/*
 * State.cpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */
#include "State.hpp"
#include "ITime.hpp"
using namespace std;

State::State(STATE_ID p_StateID):m_id(p_StateID){}

void State::addTransition(EVENT p_event, std::function<void()> p_fun)
{
    m_transitionMap.insert({p_event, p_fun});
}

void State::handleEvent(EVENT p_event)
{
    m_transitionMap[p_event]();
}

STATE_ID State::getStateId()
{
    return m_id;
}

StopWatchState::StopWatchState(): State(STATE_ID::STATE_STOPWATCH), m_count(0), m_stopFlag(true)
{}

std::string StopWatchState::onSecond()
{
    if(!m_stopFlag)
    {
        m_count++;
    }
    return std::to_string(m_count);
}

void StopWatchState::onUp()
{
    m_stopFlag = not m_stopFlag;
}

void StopWatchState::onDown()
{
    m_count = 0;
    m_stopFlag = true;
}

WatchState::WatchState(shared_ptr<ITime> p_time)
    :State(STATE_ID::STATE_WATCH), m_time(p_time)
{}

std::string WatchState::onSecond()
{
    return m_time->getCurrentTime();
}
