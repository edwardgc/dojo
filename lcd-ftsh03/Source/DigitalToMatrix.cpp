/*
 * Main.cpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#include <DigitalToMatrix.hpp>

using namespace std;

vector<LcdChar> DigitalToMatrix::convertToStr(unsigned int p_digital)
{
    m_str = std::to_string(p_digital);
    std::string l_result;
    vector<LcdChar> l_chars;
    for (auto iter : m_str)
    {
        LcdChar l_char{iter};
        l_chars.push_back(l_char);
    }
    return l_chars;
}

std::string DigitalToMatrix::printMatrixOfInputDigital(unsigned int p_digital)
{
    auto l_chars = convertToStr(p_digital);
    string str1, str2, str3;
    for(auto l_lcdChar : l_chars)
    {
        str1 += l_lcdChar.getStr()[0] + " ";
        str2 += l_lcdChar.getStr()[1] + " ";
        str3 += l_lcdChar.getStr()[2] + " ";
    }

    return str1.substr(0, str1.size()-1) + "\n"
            + str2.substr(0, str1.size()-1) + "\n"
            + str3.substr(0, str1.size()-1) + "\n";
}



int DigitalToMatrix::printNumberFromMatrix(std::string p_str)
{
    int pos = p_str.find("\n", 0);
    std::string str1 = p_str.substr(0, pos);
    p_str = p_str.substr(pos + 1);
    std::string str2 = p_str.substr(0, pos);
    p_str = p_str.substr(pos + 1);
    std::string str3 = p_str.substr(0, pos);
    int l_result = 0;
    for (int i = 0; i < pos; i = i + 4)
    {
        auto tmp = str1.substr(i, 3) + "\n" + str2.substr(i, 3) + "\n"
                + str3.substr(i, 3) + "\n";
//        l_result = l_result * 10 + m_mapStringToNumber[tmp];
    }
    return l_result;
}

