#include "stdafx.h"
#include "FindAndReplace.h"


std::string FindAndReplace(std::string const& subject, std::string const& search, std::string  const& replace)
{
	std::string finalString = "";
	for (size_t i = 0; i < subject.length();)
	{
		if (subject[i] == search[0])
		{
			if (i <= subject.length() - search.length() && (subject.substr(i, search.length()) == search))
			{
				finalString += replace;
				i += search.length();
			}
			else
			{
				finalString += subject[i];
				i++;
			}
		}
		else
		{
			finalString += subject[i];
			i++;
		}
	}
	return finalString;
}
