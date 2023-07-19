#include <Main.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace
{

const string ANSWER1="1";
const string ANSWER31="2147483648";
const string POWER1000="10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376";


}


namespace fn
{


class MainTest : public Test
{

};

TEST_F(MainTest,twoPower0_equal_1)
{
    ASSERT_EQ(ANSWER1, power(0));
}

TEST_F(MainTest, twoPower_equal_31)
{
    ASSERT_EQ(ANSWER31, power(31));
}

TEST_F(MainTest, twoPower1000)
{
    for(int i = 0; i < 1000; i++)
    {
        ASSERT_EQ(POWER1000, power(1000));
    }

}

} //namespace fn
