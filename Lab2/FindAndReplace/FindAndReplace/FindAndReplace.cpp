#include "stdafx.h"
#include "FindAndReplace.h"
#include <boost/utility/string_ref.hpp>

bool StringComparison(boost::string_ref const& subject, boost::string_ref const& search, size_t i)
{
	return (subject.substr(i, search.length()) == search);
}

std::string FindAndReplace(std::string const& subject, std::string const& search, std::string  const& replace)
{
	std::string finalString;
	for (size_t i = 0; i < subject.length();)
	{
		if (subject[i] == search[0])
		{
			if ((i + search.length() <= subject.length()) && StringComparison(subject, search, i))
			{
				finalString += replace;
				i += search.length();
				continue;
			}
		}
		finalString += subject[i];
		i++;
	}
	return finalString;
}
