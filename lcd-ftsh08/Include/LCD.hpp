#pragma once
#include <vector>
#include <string>

class Digit;

class LCD
{
public:
	LCD(int p_num);

	std::string toString();

private:
	std::vector<Digit> m_digits;
};
