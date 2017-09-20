#include <Main.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

TEST(AdditionTest,twoValues)
{
    Main main;
	ASSERT_EQ(1, main.getInt());
}
