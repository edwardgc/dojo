/*
 * Main.hpp
 *
 *  Created on: 2017Äê8ÔÂ18ÈÕ
 *      Author: cguo005
 */

#pragma once
#include <string>
#include <map>
#include"LcdChar.hpp"


class DigitalToMatrix
{
public:
    DigitalToMatrix (){}
    std::string printMatrixOfInputDigital(unsigned int p_digital);
    int printNumberFromMatrix(std::string);
private:
    vector<LcdChar> convertToStr(unsigned int p_digital);
    std::string m_str;

};



