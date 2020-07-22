/*
 * Main.cpp
 *
 *  Created on: 2017��8��18��
 *      Author: cguo005
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Main.hpp"

using namespace std;

string Main::getInt(int power)
{
    return cal(power);
}

string Main::cal(int powerNumber)
{
    vector<unsigned int> result { 1 };

    result.reserve(302);
    bool needPromote = false;

    for (int i = 0; i < powerNumber; i++)
    {
        for (auto& element:result)
        {
            element <<= 1;

            element += needPromote ? 1 : 0;

            if (element > 99999999)
            {
                needPromote = true;
                element = element - 100000000;
            }
            else
            {
                needPromote = false;
            }
        }
        if (needPromote)
        {
            result.push_back(1);
            needPromote = false;
        }
    }

    ostringstream strResult;
    strResult << result.back();

    for (int i = result.size() - 2; i >= 0; i--)
    {
        strResult << setw(8u)<<setfill('0') <<result[i];
    }

    return strResult.str();
}

