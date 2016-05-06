#include "stdafx.h"
#include "..\Lab12.9\FurSeal.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(furSeal_test)

BOOST_AUTO_TEST_CASE(when_polygon_without_water)
{
	CFurSeal furSeal_test("./test_files/without_water.txt");
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().first, 0);
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().second, 9);
}

BOOST_AUTO_TEST_CASE(when_polygon_with_some_water)
{
	CFurSeal furSeal_test("./test_files/with_some_water.txt");
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().first, 0);
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().second, 9);
}

BOOST_AUTO_TEST_CASE(when_polygon_labirint)
{
	CFurSeal furSeal_test("./test_files/labirint.txt");
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().first, 0);
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().second, 17);
}

BOOST_AUTO_TEST_CASE(when_polygon_water_labirint)
{
	CFurSeal furSeal_test("./test_files/water_labirint.txt");
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().first, 1);
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().second, 8);
}

BOOST_AUTO_TEST_CASE(when_polygon_sea)
{
	CFurSeal furSeal_test("./test_files/sea.txt");
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().first, 7);
	BOOST_CHECK_EQUAL(furSeal_test.GetAnswer().second, 2);
}

BOOST_AUTO_TEST_SUITE_END();