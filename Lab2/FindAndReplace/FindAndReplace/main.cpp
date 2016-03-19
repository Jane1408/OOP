// FindAndReplace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "FindAndReplace.h"

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		std::string subject;
		std::string search = argv[1];
		std::string replace = argv[2];

		while (std::getline(std::cin, subject))
		{
			if (subject.empty())
			{
				break;
			}
			std::cout << FindAndReplace(subject, search, replace) << std::endl;
		}
	}
	else if ((argc == 2) && (argv[1] == "help"))
	{
		std::cout << "FindAndReplace.exe <search> <replace>" << std::endl;
	}
	else if (argc > 3)
	{
		std::cout << "Error. The number of arguments exceeds the limit. Use 'help' for more information." << std::endl;
	}
	else if (argc < 3)
	{
		std::cout << "Error. Not enough arguments. Use 'help' for more information." << std::endl;
	}
	return 0;
}
