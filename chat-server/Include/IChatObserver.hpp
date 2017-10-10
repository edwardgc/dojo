/*
 * IChatObserver.hpp
 *
 *  Created on: 2017Äê10ÔÂ11ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <memory>
#include "ISession.hpp"

class IChatObserver
{
public:
    virtual void onNewSession(std::shared_ptr<ISession>) = 0;
    virtual void onReceive(std::shared_ptr<ISession>, std::string message);
    virtual void onSessionClose(std::shared_ptr<ISession>) = 0;
    virtual ~IChatObserver() = default;
};


