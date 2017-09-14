#include <Fsm.hpp>
#include "State.hpp"

using namespace std;

Fsm::Fsm (shared_ptr<ITime> p_time)
    :m_stateStopWatch(make_shared<StopWatchState>()),
     m_stateWatch(make_shared<WatchState>(p_time)),
     m_curState(m_stateStopWatch)
{
    m_stateStopWatch->addTransition(EVENT::SWITCH_EVENT, std::bind(&Fsm::excuteWhenStateOn, this));
    m_stateWatch->addTransition(EVENT::SWITCH_EVENT, std::bind(&Fsm::excuteWhenStateOff, this));
}

void Fsm::processEvent(EVENT p_event)
{
    m_curState->handleEvent(p_event);
}

void Fsm::excuteWhenStateOn()
{
   transitTo(m_stateWatch);
}

void Fsm::excuteWhenStateOff()
{
    transitTo(m_stateStopWatch);
}

void Fsm::transitTo(shared_ptr<State> p_newState)
{
    m_curState = p_newState;
}

shared_ptr<State> Fsm::getCurrentState()
{
    return m_curState;
}
