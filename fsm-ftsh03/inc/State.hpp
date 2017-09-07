/*
 * State.hpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <map>
#include <functional>
#include "ILogger.hpp"

enum class EVENT
{
    SWITCH_EVENT
};

typedef std::map<EVENT, std::function<void()>> TransitionMap;
enum class STATE_ID
{
    STATE_ON,
    STATE_HALF_ON,
    STATE_OFF,
};


class State{
public:
    State(STATE_ID p_StateID, ILogger &p_logger);
    void addTransition(EVENT p_event, std::function<void()> p_fun);
    void handleEvent(EVENT p_event);
    void exit();
    void enter();
private:
    TransitionMap m_transitionMap;
    STATE_ID m_id;
    ILogger &m_logger;
};


