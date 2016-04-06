#include "stdafx.h"
#include "OccurrenceOfWords.h"

void ConvertToLowercase(std::string & inputString)
{
	for (auto &it : inputString)
	{
		it = char(tolower(it));
	}
}

void CountWords(std::string const& word, std::map<std::string, size_t> & wordsStore)
{
	auto it = wordsStore.find(word);
	if (it != wordsStore.end())
	{
		it->second++;
	}
	else
	{
		wordsStore.insert(std::pair<std::string, size_t>(word, 1));
	}
}

bool CheckDelimiterSymbol(const char & symbol)
{
	return ((symbol == '	') || (symbol == ' ') || (symbol == '.') || (symbol == ','));
}

std::map<std::string, size_t> FindAndCountWordsFromString(std::string & inputString)
{
	std::string word;
	std::map<std::string, size_t> wordsStore;
	ConvertToLowercase(inputString);
	for (size_t i = 0; i < inputString.length(); ++i)
	{
		if (!CheckDelimiterSymbol(inputString[i]))
		{
			word += inputString[i];
		}
		if (CheckDelimiterSymbol(inputString[i]) || ((i == inputString.length() - 1) && !CheckDelimiterSymbol(inputString[i])))
		{
			if (!word.empty())
			{
				CountWords(word, wordsStore);
				word = "";
			}
		}
	}
	return wordsStore;
}

