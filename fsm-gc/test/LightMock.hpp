#include <gmock/gmock.h>
#include "ILight.hpp"

class LightMock : public ILight
{
public:
    MOCK_METHOD0(turnOn, void());
    MOCK_METHOD0(turnOff, void());
};
