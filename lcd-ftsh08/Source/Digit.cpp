#include "Digit.hpp"

namespace
{
std::vector<std::vector<std::string>> num2string = 
	{{"._.","|.|","|_|"},
	 {"...","..|","..|"},
	 {"._.","._|","|_."},
	 {"._.","._|","._|"},
	 {"...","|_|","..|"},
	 {"._.","|_.","._|"},
	 {"._.","|_.","|_|"},
	 {"._.","..|","..|"},
	 {"._.","|_|","|_|"},
	 {"._.","|_|","..|"}};
}


Digit::Digit(int p_num):line0(num2string[p_num][0]),
						line1(num2string[p_num][1]),
						line2(num2string[p_num][2])
{
}


