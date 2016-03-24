#include "stdafx.h"
#include <string>
#include "..\FindAndReplace\FindAndReplace.h"

BOOST_AUTO_TEST_SUITE(Replace_function)
BOOST_AUTO_TEST_SUITE(when_one_of_arguments_is_empty)
BOOST_AUTO_TEST_CASE(when_search_string_is_empty_return_string_without_replace)
{
	std::string subject = "Hello";
	std::string search = "";
	std::string replace = "bye";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "Hello");
}

BOOST_AUTO_TEST_CASE(when_replace_string_is_empty_return_string_with_replacement_serach_string_to_empty_string)
{
	std::string subject = "Hello";
	std::string search = "H";
	std::string replace = "";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "ello");
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_CASE(when_subject_string_not_contains_search_string_should_give_string_without_replace)
{
	std::string subject = "Hello";
	std::string search = "world";
	std::string replace = "bye";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "Hello");
}

BOOST_AUTO_TEST_CASE(when_subject_string_contains_search_string_should_give_string_with_replace)
{
	std::string subject = "All cats like fish";
	std::string search = "cats";
	std::string replace = "people";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "All people like fish");
}

BOOST_AUTO_TEST_CASE(when_subject_string_contains_search_string__with_another_register_should_give_string_with_replace)
{
	std::string subject = "This is an apple";
	std::string search = "is";
	std::string replace = "IS";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "ThIS IS an apple");
}

BOOST_AUTO_TEST_CASE(when_replace_string_contains_search_string_should_give_string_with_replace)
{
	std::string subject = "blablabla";
	std::string search = "bla";
	std::string replace = "blabla";

	std::string str = FindAndReplace(subject, search, replace);
	BOOST_CHECK(str == "blablablablablabla");
}
BOOST_AUTO_TEST_SUITE_END()
