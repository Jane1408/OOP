// solve.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

bool CheckArguments(int argc, const char * firstArgument)
{
	
	if (argc == 4)
		return true;
	else if (argc == 2 && std::string(firstArgument) == "help")
	{
		std::cout << "solve.exe <A> <B> <C>" << std::endl;
		return false;
	}
	else if (argc > 4)
	{
		std::cout << "Error. The number of arguments exceeds the limit. Use 'help' for more information." << std::endl;
		return false;
	}

	else if (argc < 4)
	{
		std::cout << "Error. Not enough arguments. Use 'help' for more information." << std::endl;
		return false;
	}

}

bool IsCorrectNumber(std::string const& number)
{
	long num = atoi(number.c_str());
	return num <= INT_MAX;
}

bool CheckNumbers(std::string const& firstArgument, std::string const& secondArgument, std::string const& thirdArgument)
{
	if (IsCorrectNumber(firstArgument) && IsCorrectNumber(secondArgument) && IsCorrectNumber(thirdArgument))
		return true;
	std::cout << "Error. Too high value of number." << std::endl;
	return false;
}

std::pair<double, double> FindRoots(int parameterA, int parameterB, int parameterC, bool & wasError)
{
	std::pair <double, double> roots = {};
	int discriminant = 0;
	discriminant = (parameterB * parameterB) - (4 * parameterA * parameterC);
	if (discriminant >= 0)
	{
		roots.first = double(-parameterB - sqrt(discriminant)) / (2 * parameterA);
		roots.second = double(-parameterB + sqrt(discriminant)) / (2 * parameterA);
		return roots;
	}
	wasError = true;
	std::cout << "There is no real root." << std::endl;
	return roots;
}

int main(int argc, char* argv[])
{
	bool wasError = false;
	std::pair<double, double> roots = {};
	if (CheckArguments(argc, argv[1]))
	{
		if (CheckNumbers(argv[1], argv[2], argv[3]))
		{
			int parameterA = atoi(argv[1]);
			int parameterB = atoi(argv[2]);
			int parameterC = atoi(argv[3]);

			if (parameterA != 0)
			{
				roots = FindRoots(parameterA, parameterB, parameterC, wasError);
				std::cout.precision(4);
				if (roots.first != roots.second && !wasError)
					std::cout << "Two roots " << roots.first << " " << roots.second << std::endl;
				else if (roots.first == roots.second && !wasError)
					std::cout << "One root " << roots.first << std::endl;
			}
			else
				std::cout << "Error. The equation is not quadratic. " << std::endl;
		}
	}
	return 0;
}

