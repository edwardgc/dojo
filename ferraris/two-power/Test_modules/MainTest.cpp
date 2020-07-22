#include <Main.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;


TEST(AdditionTest,twoPower2Equal_4)
{
    Main main;
    ASSERT_EQ("4", main.getInt(2));
}

TEST(AdditionTest,twoPower0Equal_1)
{
    Main main;
    ASSERT_EQ("1", main.getInt(0));
}

TEST(AdditionTest,twoPower32Equal_4294967296)
{
    Main main;
    ASSERT_EQ("4294967296", main.getInt(32));
}

TEST(AdditionTest,twoPower64Equal_18446744073709551616)
{
    Main main;
    ASSERT_EQ("18446744073709551616", main.getInt(64));
}

TEST(AdditionTest,twoPower1000LengthEqual_302)
{
    Main main;
    for(int i=0; i<100; ++i){
    ASSERT_EQ(302u, main.getInt(1000).length());}
}
