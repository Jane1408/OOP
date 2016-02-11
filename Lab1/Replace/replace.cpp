// replace.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <io.h>
#include <fstream>
#include <string>
#include <sys/stat.h>


const int64_t MAX_SIZE_OF_FILE = 17179869184;

bool isArgumentsCorrect(int argc, char * argv)
{
	if ((argc == 5) || (argc == 4))
	{
		return true;
	}
	else if ((argc == 2) && (std::string(argv) == "help"))
	{
		printf("replace.exe <inputFile> <outputFile> <searchString> <replaceString>");
		return false;
	}

	else if (argc > 5)
	{
		printf("Error. The number of arguments exceeds the limit. You need 4 or 5 arguments.");
		return false;
	}

	else
	{
		printf("Error. Not enough arguments. You need 4 or 5 arguments.");
		return false;
	}
}

bool isFileSizeCorrect(char * input)
{
	if (_access(input, 0) == -1)
	{ 
		printf("Error. File %s is not found.", input);
		return false;
	}
	struct stat fi;
	stat(input, &fi);
	if (int(fi.st_size) < MAX_SIZE_OF_FILE)
	{
		return true;
	}
	else
	{
		printf("Error. Invalid size of file.");
		return false;
	}
}

void OnlyRewrite(char * input, char * output)
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

void ReplaceAndRewrite(char * input, char * output, char * search, char * replace)
{

	std::ifstream inputFile(input);
	std::ofstream outputFile(output);

	std::string searchString(search);
	std::string replaceString(replace);
	std::string line;

	while (std::getline(inputFile, line))
	{
		for (int i = 0; i < line.length();)
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
	if (isArgumentsCorrect(argc, argv[1]) && isFileSizeCorrect(argv[1]))
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