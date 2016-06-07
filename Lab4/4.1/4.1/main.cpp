// main.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "ComandHandler.h"

int main()
{
	CComandHandler commandHandler;
	std::string body;
	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << ">";
		std::cin >> body;
		if (!std::cin.fail())
		{
			commandHandler.SetBody(body);
		}
	}
	commandHandler.DisplayInfo();
    return 0;
}

