
#pragma once
#include "ILight.hpp"
#include "State.hpp"
#include <utility>
#include <memory>
class State;
class Fsm;
class ILogger;

enum class EVENT;

class Fsm
{
public:
	Fsm() = default;
	Fsm (ILight &p_light, ILogger &p_logger);
	void processEvent(EVENT p_event);
	~Fsm() = default;
private:
	void transitTo(State &p_newState);
	void excuteWhenStateOn();
	void excuteWhenStateHalfOn();
	void excuteWhenStateOff();

	ILight &m_light;
	ILogger &m_logger;

	State m_stateOn;
	State m_stateHalfOn;
	State m_stateOff;
    State *m_curState;
};
