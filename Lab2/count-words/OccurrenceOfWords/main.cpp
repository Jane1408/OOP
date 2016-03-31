// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "OccurrenceOfWords.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc == 1)
	{
		std::map <std::string, size_t> wordsStore;
		std::string inputString;
		while (std::getline(std::cin, inputString))
		{
			wordsStore.clear();
			if (inputString.empty())
			{
				break;
			}
			wordsStore = FindAndCountWordsFromString(inputString);
			for (auto &it : wordsStore)
			{
				std::cout << it.first << " -> " << it.second << std::endl;
			}

		}
	}
	return 0;
}
