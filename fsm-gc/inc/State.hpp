/*
 * State.hpp
 *
 *  Created on: 2017Äê8ÔÂ7ÈÕ
 *      Author: cguo005
 */

#pragma once

#include "IState.hpp"
#include "iostream"
#include <Functional>
#include <map>

enum class StateId
{
    ON,
    OFF
};

using namespace std;

class State : public IState
{
public:
    State(StateId p_id) : m_id(p_id){}

    void handle(Event p_event) override
    {
        auto ite = m_transitions.find(p_event);
        if(ite != m_transitions.end())
        {
            ite->second(p_event);
        }
        else
        {
            cout << "State " << static_cast<int>(m_id) <<
                    " No transition found for event " << static_cast<int>(p_event) << endl;
        }
    }
    ~State() = default;
protected:
    StateId m_id;
    map<Event, function<void(const Event&)>> m_transitions;
};

