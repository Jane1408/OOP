// replace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <iostream>
#include <string>


bool IsPathExists(const char * input)
{
	if (_access(input, 0) == -1)
	{
		std::cout << "Error. File " << std::string(input) << " is not found." << std::endl;
		return false;
	}
	return true;
}

bool CheckArguments(int argc, const char * argv)
{
	if ((argc == 5) || (argc == 4))
	{
		if (IsPathExists(argv))
			return true;
		else
			return false;
	}
	else if ((argc == 2) && (std::string(argv) == "help"))
	{
		std::cout << "replace.exe <inputFile> <outputFile> <searchString> <replaceString>" << std::endl;
		return false;
	}

	else if (argc > 5)
	{
		std::cout << "Error. The number of arguments exceeds the limit. Use 'help' for more information." << std::endl;
		return false;
	}

	else
	{
		std::cout << "Error. Not enough arguments. Use 'help' for more information." << std::endl;
		return false;
	}
}

void OnlyRewrite(const char * input, const char * output)
{
	std::ifstream inputFile(input);
	std::ofstream outputFile(output);

	std::string line;

	while (std::getline(inputFile, line))
	{
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();
}

void ReplaceAndRewrite(const char * input, const char * output, std::string searchString, std::string replaceString)
{

	std::ifstream inputFile(input);
	std::ofstream outputFile(output);

	std::string line;

	while (std::getline(inputFile, line))
	{
		for (size_t i = 0; i < line.length();)
		{
			if (line[i] == searchString[0])
			{
				if (i <= line.length() - searchString.length() && (line.substr(i, searchString.length()) == searchString))
				{
					i += searchString.length();
					outputFile << replaceString;
				}
				else
				{
					outputFile << line[i];
					i++;
				}
			}
			else
			{
				outputFile << line[i];
				i++;
			}
		}
	}

	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[])
{
	if (CheckArguments(argc, argv[1]))
	{
		if (argc == 4) 
		{
			OnlyRewrite(argv[1], argv[2]);
		}
		else 
		{
			ReplaceAndRewrite(argv[1], argv[2], argv[3], argv[4]);
		}
	}
    return 0;
}