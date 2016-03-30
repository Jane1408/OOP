// solve.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

bool CheckArguments(std::vector<std::string> const& args)
{
	if (args.size() == 4)
	{
		return true;
	}
	else if ((args.size() == 2) && (args[1] == "help"))
	{
		std::cout << "solve.exe <A> <B> <C>" << std::endl;
		return false;
	}
	else if (args.size() > 4)
	{
		std::cout << "Error. The number of arguments exceeds the limit. Use 'help' for more information." << std::endl;
		return false;
	}
	else // when args.size() < 4
	{
		std::cout << "Error. Not enough arguments. Use 'help' for more information." << std::endl;
		return false;
	}
}

bool IsCorrectNumber(std::string const& number)
{
	if (number == "0")
		return true;
	int num = atoi(number.c_str());
	if (num == INT_MAX)
	{
		std::cout << "Error. Too high value of number." << std::endl;
		return false;
	}
	else if (num == 0)
	{
		std::cout << "Error. Not correct value of number." << std::endl;
		return false;
	}
	return true;
}

bool CheckNumbersArguments(std::vector<std::string> & args)
{
	return (IsCorrectNumber(args[1]) && IsCorrectNumber(args[2]) && IsCorrectNumber(args[3]));
}

double DiscriminantCalculation(double parameterA, double parameterB, double parameterC)
{
	return (parameterB * parameterB) - (4 * parameterA * parameterC);
}

std::pair<double, double> FindRoots(double parameterA, double parameterB, double parameterC, double & discriminant)
{
	return std::pair <double, double>((-parameterB - sqrt(discriminant)) / (2 * parameterA), (-parameterB + sqrt(discriminant)) / (2 * parameterA));
}

double FindSingleRoot(double parameterA, double parameterB, double parameterC, double & discriminant)
{
	return (-parameterB + sqrt(discriminant)) / (2 * parameterA);
}

void RootCalculation(double parameterA, double parameterB, double parameterC)
{
	double root = 0;
	std::pair<double, double> roots = {0, 0};
	double discriminant = DiscriminantCalculation(parameterA, parameterB, parameterC);
	if (discriminant > 0)
	{
		roots = FindRoots(parameterA, parameterB, parameterC, discriminant);
		std::cout << "Two roots " << roots.first << " " << roots.second << std::endl;
	}
	else if (discriminant == 0)
	{
		root = FindSingleRoot(parameterA, parameterB, parameterC, discriminant);
		std::cout << "One root " << root << std::endl;
	}
	else
	{
		std::cout << "There is no real root." << std::endl;
	}
}
int main(int argc, char* argv[])
{
	std::vector<std::string> args(argv, argv + argc);
	std::cout.precision(4);
	if (CheckArguments(args))
	{
		if (CheckNumbersArguments(args))
		{
			double parameterA = atoi(argv[1]);
			double parameterB = atoi(argv[2]);
			double parameterC = atoi(argv[3]);
			if (parameterA != 0)
			{
				RootCalculation(parameterA, parameterB, parameterC);
			}
			else
			{
				std::cout << "Error. The equation is not quadratic. " << std::endl;
			}
		}
	}
	return 0;
}

