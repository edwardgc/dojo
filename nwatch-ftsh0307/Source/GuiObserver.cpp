/*
 * Main.cpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#include <GuiObserver.hpp>
#include <ITime.hpp>
#include <Fsm.hpp>
GuiObserver::GuiObserver(shared_ptr<ITime> p_time)
    :m_fsm(p_time)
{

}

void GuiObserver::onSwitchClick()
{
    m_fsm.getCurrentState()->handleEvent(EVENT::SWITCH_EVENT);
}

void GuiObserver::onUpClick()
{
    m_fsm.getCurrentState()->onUp();
}

void GuiObserver::onDownClick()
{
    m_fsm.getCurrentState()->onDown();
}

std::string GuiObserver::onSecond()
{
    return m_fsm.getCurrentState()->onSecond();
}

