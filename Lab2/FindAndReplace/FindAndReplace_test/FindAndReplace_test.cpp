#include "stdafx.h"
#include <string>
#include "..\FindAndReplace\FindAndReplace.h"

BOOST_AUTO_TEST_SUITE(Replace_function)
BOOST_AUTO_TEST_CASE(give_empty_string)
{
	std::string subject = "";
	std::string search = "hello";
	std::string replace = "world";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "");
}

BOOST_AUTO_TEST_CASE(give_subject_string)
{
	std::string subject = "Hello";
	std::string search = "world";
	std::string replace = "bye";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "Hello");
}

BOOST_AUTO_TEST_CASE(give_string_papama)
{
	std::string subject = "mamama";
	std::string search = "mama";
	std::string replace = "papa";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "papama");
}

BOOST_AUTO_TEST_SUITE_END()
