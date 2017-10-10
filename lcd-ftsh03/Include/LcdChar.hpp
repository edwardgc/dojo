/*
 * LcdChar.hpp
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: cguo005
 */

#pragma once
#include<string>
#include<map>
#include<vector>

using namespace std;

class LcdChar
{
public:
    LcdChar(char p_num);

    const vector<string>& getStr() const
    {
        return m_str;
    }

private:
    static std::map<std::string, int> createMapForStringToNumber();
    char m_num;
    vector<string> m_str;
    static std::map<char, std::string> m_mapOfFirstLine;
    static std::map<char, std::string> m_mapOfSecondLine;
    static std::map<char, std::string> m_mapOfThirdLine;
    static std::map<std::string, int> m_mapStringToNumber;
};



