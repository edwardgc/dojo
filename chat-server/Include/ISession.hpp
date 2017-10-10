
#pragma once

class ISession
{
public:
    virtual void deliver(const std::string&) = 0;
    virtual std::string getName() const = 0;
    virtual void setName(const std::string&) = 0;
    virtual ~ISession() = default;
};


