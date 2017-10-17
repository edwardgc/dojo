/*
 * IReceiver.hpp
 *
 *  Created on: 2017��10��17��
 *      Author: xrx
 */
#include <ios>

class IReceiver
{
public:
    virtual void onReceive(std::string msg) = 0;
    virtual ~IReceiver() = default;
};


