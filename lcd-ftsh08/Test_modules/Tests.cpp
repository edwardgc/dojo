#include <gtest/gtest.h>
#include <string.h>
#include "LCD.hpp"
#include "Digit.hpp"

TEST(DigitLCD, checkZero)
{
	LCD l(0);
	std::string zero = "._.\n|.|\n|_|\n";
	EXPECT_EQ(zero, l.toString());
}


TEST(DigitLCD, checkOne)
{
	LCD l(1);
	std::string one = "...\n..|\n..|\n";
	EXPECT_EQ(one, l.toString());
}

TEST(DigitLCD, checkOtherNum)
{
	LCD l(6);
	std::string six = "._.\n|_.\n|_|\n";
	EXPECT_EQ(six, l.toString());
}

TEST(DigitLCD, checkBiggerThanTenNum)
{
	LCD l(16);
	std::string sixteen = "... ._.\n..| |_.\n..| |_|\n";
	EXPECT_EQ(sixteen, l.toString());
}

TEST(DigitLCD, check910)
{
	LCD l(910);
	std::string n910 = "._. ... ._.\n|_| ..| |.|\n..| ..| |_|\n";
	EXPECT_EQ(n910, l.toString());
	std::cout << n910 << std::endl;
}
