// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "HttpUrl.h"


int main()
{
	std::string str;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (!std::cin.fail())
		{
			CHttpUrl parser(str);
		}
	}
	return 0;
}

