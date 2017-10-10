/*
 * LcdChar.cpp
 *
 *  Created on: 2017Äê9ÔÂ21ÈÕ
 *      Author: cguo005
 */
#include"LcdChar.hpp"

LcdChar::LcdChar(char p_num):m_num(p_num){
    m_str.push_back(m_mapOfFirstLine[m_num]);
    m_str.push_back(m_mapOfSecondLine[m_num]);
    m_str.push_back(m_mapOfThirdLine[m_num]);
}

std::map<char, std::string> LcdChar::m_mapOfFirstLine = {
        { '0', "._." }, { '1', "..." }, { '2', "._." }, { '3', "._." }, { '4',
                "..." }, { '5', "._." }, { '6', "._." }, { '7', "._." }, { '8',
                "._." }, { '9', "._." } };

std::map<char, std::string> LcdChar::m_mapOfSecondLine = {
        { '0', "|.|" }, { '1', "..|" }, { '2', "._|" }, { '3', "._|" }, { '4',
                "|_|" }, { '5', "|_." }, { '6', "|_." }, { '7', "..|" }, { '8',
                "|_|" }, { '9', "|_|" } };

std::map<char, std::string> LcdChar::m_mapOfThirdLine = {
        { '0', "|_|" }, { '1', "..|" }, { '2', "|_." }, { '3', "._|" }, { '4',
                "..|" }, { '5', "._|" }, { '6', "|_|" }, { '7', "..|" }, { '8',
                "|_|" }, { '9', "..|" } };

std::map<std::string, int> LcdChar::createMapForStringToNumber()
{
    std::map<std::string, int> l_map { };
    for (char i = '0'; i <= '9'; i++)
    {
        auto l_str = m_mapOfFirstLine[i] + "\n" + m_mapOfSecondLine[i] + "\n"
                + m_mapOfThirdLine[i] + "\n";
        l_map[l_str] = i - '0';
    }
    return l_map;
}

std::map<std::string, int> LcdChar::m_mapStringToNumber =
        LcdChar::createMapForStringToNumber();



