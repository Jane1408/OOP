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
		while (std::getline(std::cin, subject))
		{
			if (subject.empty())
			{
				break;
			}
			std::cout << FindAndReplace(subject, argv[1], argv[2]) << std::endl;
		}
	}
	return 0;
}
