#include "LCD.hpp"
#include "Digit.hpp"


LCD::LCD(int p_num)
{
	while(p_num > 10)
	{
		m_digits.emplace_back(p_num%10);
		p_num =p_num/10;
	}
	m_digits.emplace_back(p_num);
}

std::string LCD::toString()
{
	std::string temp0,temp1,temp2;
    for(auto it = m_digits.rbegin();it != m_digits.rend();it++)
	{
       temp0 += it->line0 + ' ';
	   temp1 += it->line1 + ' ';
	   temp2 += it->line2 + ' ';
	}
	return   temp0.substr(0, temp0.size()-1) +'\n'
		   + temp1.substr(0, temp1.size()-1) +'\n'
		   + temp2.substr(0, temp2.size()-1) +'\n';
}
