#include "stdafx.h"
#include <map>
#include <string>
#include <windows.h>
#include "..\OccurrenceOfWords\OccurrenceOfWords.h"

using namespace std;

bool CheckEqualMaps(map <string, size_t> & firstMap, map <string, size_t> & secondMap)
{
	for (auto it : firstMap)
	{
		if ((secondMap.find(it.first) == secondMap.end()) || (secondMap.find(it.first)->second != it.second))
		{
			return false;
		}
	}
	return true;
}

BOOST_AUTO_TEST_SUITE(FindAndCountWordsFromString_function)

BOOST_AUTO_TEST_SUITE(when_input_string_is_empty)
BOOST_AUTO_TEST_CASE(should_make_empty_map)
{
	string inputString = "";
	map <string, size_t> wordsStore = FindAndCountWordsFromString(inputString);
	BOOST_CHECK(wordsStore.empty());
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_input_string_contains_same_russian_words_in_different_registers)
BOOST_AUTO_TEST_CASE(should_considered_that_same_russian_words_in_different_registers_are_equal)
{
	setlocale(LC_ALL, "Russian");
	string inputString = "котики Котики кОтики";
	map <string, size_t> checkStore = { { "котики", 3 } };
	map <string, size_t> wordsStore = FindAndCountWordsFromString(inputString);
	BOOST_CHECK(CheckEqualMaps(wordsStore, checkStore));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_input_string_contains_same_words_in_different_registers)
BOOST_AUTO_TEST_CASE(should_considered_that_same_words_in_different_registers_are_equal)
{
	string inputString = "Meow MeoW mEoW MeOw";
	map <string, size_t> checkStore = { { "meow", 4}};
	map <string, size_t> wordsStore = FindAndCountWordsFromString(inputString);
	BOOST_CHECK(CheckEqualMaps(wordsStore, checkStore));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_input_string_contains_multiple_spaces_in_a_row)
BOOST_AUTO_TEST_CASE(should_count_the_number_of_words_excluding_the_number_of_spaces)
{
	string inputString = "All   should  love		cats";
	map <string, size_t> checkStore = { { "all", 1 },
	{ "should", 1 },
	{ "love", 1 }, 
	{ "cats", 1 }};
	map <string, size_t> wordsStore = FindAndCountWordsFromString(inputString);
	BOOST_CHECK(CheckEqualMaps(wordsStore, checkStore));
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
