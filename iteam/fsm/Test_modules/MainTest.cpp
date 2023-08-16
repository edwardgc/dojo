#include <Main.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace fn
{

class MainTest : public Test
{

};

TEST_F(MainTest, test)
{
    ASSERT_EQ(1, 1);
}

} //namespace fn
