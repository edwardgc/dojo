#include <DigitalToMatrix.hpp>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

struct TestDigitalToMatrix : public ::testing::Test
{
    DigitalToMatrix l_toMatrix;
};
#if 0
TEST_F(TestDigitalToMatrix,printTheFirstRowOf0)
{
	EXPECT_EQ("._.\n", l_toMatrix.printTheFirstRowOfMatrix(0));
}

TEST_F(TestDigitalToMatrix,printTheFirstRowOf910)
{
    EXPECT_EQ("._. ... ._.\n", l_toMatrix.printTheFirstRowOfMatrix(910));

}

TEST_F(TestDigitalToMatrix,printTheSecondRowOf910)
{
    EXPECT_EQ("|_| ..| |.|\n", l_toMatrix.printTheSecondRowOfMatrix(910));
}

TEST_F(TestDigitalToMatrix,printTheThirdRowOf910)
{
    EXPECT_EQ("..| ..| |_|\n", l_toMatrix.printTheThirdRowOfMatrix(910));
}
#endif
TEST_F(TestDigitalToMatrix,printMatrixOf910)
{
    cout << l_toMatrix.printMatrixOfInputDigital(910) << endl;
    EXPECT_EQ("._. ... ._.\n|_| ..| |.|\n..| ..| |_|\n", l_toMatrix.printMatrixOfInputDigital(910));
}

TEST_F(TestDigitalToMatrix,printOneNumberFromMatrix)
{
    EXPECT_EQ(9, l_toMatrix.printNumberFromMatrix("._.\n|_|\n..|\n"));
}

TEST_F(TestDigitalToMatrix,print910FromMatrix)
{
    EXPECT_EQ(910, l_toMatrix.printNumberFromMatrix("._. ... ._.\n|_| ..| |.|\n..| ..| |_|\n"));
}
