/*
 * Main.cpp
 *
 *  Created on: 2017��8��18��
 *      Author: cguo005
 */
#include<iostream>
#include<sstream>
#include <cstdint>
#include <string>
#include<Main.hpp>
#include<algorithm>
#include <iomanip>

using namespace std;

namespace
{
constexpr int HUNDRED_MILLION = 100000000;
}

string power(int index)
{
    int result[302] = { 0 };
    result[0] = 1;
    int count = 0;
    int seed = 2;
    if(index%4 == 0){
        index /= 4;
        seed = 16;
    }
    for (int i = 0; i < index; i++)
    {
        int carry = 0;
        string tmp;
        for (int j = 0; j <= count; j++)
        {
            int current = result[j] * seed + carry;
            result[j] = current % HUNDRED_MILLION;
            carry = current / HUNDRED_MILLION;
        }
        if (carry != 0)
        {
            count++;
            result[count] = carry;
        }
    }
    stringstream ss;
    ss << result[count];
    for (int i = count-1; i >= 0; i--)
    {
        ss << setfill('0') << setw(8) << result[i];
    }
    return ss.str();
}
