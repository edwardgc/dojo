/*
 * Invoker.cpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */
#include <memory>
#include <string>
#include "Invoker.hpp"
#include "User.hpp"

using namespace std;

void Invoker::invoke(shared_ptr<User> p_user, string message)
{
    string l_command = message.substr(1, message.find(' ')-1);
    string l_arg = message.substr(message.find(' ')+1);
    if(m_commands.find(l_command) != m_commands.end())
    {
        m_commands[l_command]->run(p_user, l_arg);
    }
}


