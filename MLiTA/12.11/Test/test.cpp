#include "stdafx.h"
#include "../KrasckalRoads/KrasckalRoad.h"

BOOST_AUTO_TEST_SUITE(Kraskal_roads_testing)

BOOST_AUTO_TEST_CASE(when_input_file_is_empty)
{
	CKrasckalRoad test;
	test.SetLandMap("./testing_files/input_empty.txt");
	BOOST_CHECK_EQUAL(test.GetPrice(), 0);
	BOOST_CHECK(test.GetAsphaltRoads().empty());
}

BOOST_AUTO_TEST_CASE(when_input_file_is_correct)
{
	CKrasckalRoad test;
	test.SetLandMap("./testing_files/input2.txt");
	std::multimap<int, int> rightAnswer = { {1, 2}, {1, 3}, {3, 4}, {4, 5} };
	BOOST_CHECK_EQUAL(test.GetPrice(), 11);
	BOOST_CHECK_EQUAL(test.GetAsphaltRoads().size(), 4);
	BOOST_CHECK(test.GetAsphaltRoads() == rightAnswer);
}


BOOST_AUTO_TEST_SUITE_END()