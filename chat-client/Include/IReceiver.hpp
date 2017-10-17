/*
 * IReceiver.hpp
 *
 *  Created on: 2017Äê10ÔÂ17ÈÕ
 *      Author: xrx
 */
#include <ios>

class IReceiver
{
public:
    virtual void onReceive(std::string msg) = 0;
    virtual ~IReceiver() = default;
};


