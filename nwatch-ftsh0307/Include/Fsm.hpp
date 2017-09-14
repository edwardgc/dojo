
#pragma once

#include "State.hpp"
#include <utility>
#include <memory>
class State;
class Fsm;
class ITime;
using namespace std;

enum class EVENT;

class Fsm
{
public:
	Fsm(shared_ptr<ITime> p_time);
	void processEvent(EVENT p_event);
	shared_ptr<State> getCurrentState();
	~Fsm() = default;
private:
	void transitTo(shared_ptr<State> p_newState);
	void excuteWhenStateOn();
	void excuteWhenStateOff();

	shared_ptr<State> m_stateStopWatch;
	shared_ptr<State> m_stateWatch;
	shared_ptr<State> m_curState;
};
