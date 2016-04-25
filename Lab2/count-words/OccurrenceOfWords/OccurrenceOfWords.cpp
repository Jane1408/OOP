#include "stdafx.h"
#include "OccurrenceOfWords.h"

void ConvertToLowercase(std::string & word)
{
	for (auto &it : word)
	{
		it = char(tolower(it));
	}
}

bool IsDelimiter(const char & symbol)
{
	return ((symbol == '\t') || (symbol == ' ') || (symbol == '.') || (symbol == ','));
}

std::map<std::string, size_t> FindAndCountWordsFromString(std::string const& inputString)
{
	std::string word;
	std::map<std::string, size_t> wordsStore;
	for (size_t i = 0; i < inputString.length(); ++i)
	{
		if (!IsDelimiter(inputString[i]))
		{
			word += inputString[i];
		}
		if (IsDelimiter(inputString[i]) || ((i == inputString.length() - 1) && !IsDelimiter(inputString[i])))
		{
			if (!word.empty())
			{
				ConvertToLowercase(word);
				++wordsStore[word];
				word = "";
			}
		}
	}
	return wordsStore;
}

