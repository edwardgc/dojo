#include <Fsm.hpp>

using namespace std;


Fsm::Fsm (ILight &p_light, ILogger &p_logger)
    :m_light(p_light),
     m_logger(p_logger),
     m_stateOn(STATE_ID::STATE_ON, m_logger),
     m_stateHalfOn(STATE_ID::STATE_HALF_ON, m_logger),
     m_stateOff(STATE_ID::STATE_OFF, m_logger),
     m_curState(&m_stateOff)
{
    m_stateOn.addTransition(EVENT::SWITCH_EVENT, std::bind(&Fsm::excuteWhenStateOn, this));
    m_stateHalfOn.addTransition(EVENT::SWITCH_EVENT, std::bind(&Fsm::excuteWhenStateHalfOn, this));
    m_stateOff.addTransition(EVENT::SWITCH_EVENT, std::bind(&Fsm::excuteWhenStateOff, this));
}

void Fsm::processEvent(EVENT p_event)
{
    m_curState->handleEvent(p_event);
}

void Fsm::excuteWhenStateOn()
{
   m_light.turnOff();
   transitTo(m_stateOff);
}

void Fsm::excuteWhenStateHalfOn()
{
   m_light.turnOn();
   transitTo(m_stateOn);
}

void Fsm::excuteWhenStateOff()
{
    m_light.turnHalfOn();
    transitTo(m_stateHalfOn);
}

void Fsm::transitTo(State &p_newState)
{
    m_curState->exit();
    m_curState = &p_newState;
    p_newState.enter();

}
