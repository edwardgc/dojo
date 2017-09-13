/*
 * State.hpp
 *
 *  Created on: 2017Äê8ÔÂ10ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <map>
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

class ITime;
enum class EVENT
{
    SWITCH_EVENT
};

typedef std::map<EVENT, std::function<void()>> TransitionMap;
enum class STATE_ID
{
    STATE_STOPWATCH = 0,
    STATE_WATCH,
};


class State{
public:
    State(STATE_ID p_StateID);
    void addTransition(EVENT p_event, std::function<void()> p_fun);
    void handleEvent(EVENT p_event);
    void exit();
    void enter();
    virtual string onSecond() = 0;
    virtual void onUp(){}
    virtual void onDown(){}
    STATE_ID getStateId();
    virtual ~State(){}
private:
    TransitionMap m_transitionMap;
    STATE_ID m_id;
};

class StopWatchState : public State
{
public:
    StopWatchState();
    string onSecond();
    void onUp();
    void onDown();
private:
    int m_count;
    bool m_stopFlag;
};

class WatchState : public State
{
public:
    WatchState(std::shared_ptr<ITime> p_time);
    string onSecond();
private:
    std::shared_ptr<ITime> m_time;
};


