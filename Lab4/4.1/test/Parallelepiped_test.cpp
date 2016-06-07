#include "stdafx.h"
#include "../4.1/Parallelepiped.h"

struct Parallelepiped_
{
	double expectidHeight = 5;
	double expectedWidth = 1;
	double expectidDepth = 10;
	double expectedVolume = 50;
	double expectedWeight = 6;
	CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedWeight, expectedWidth, expectidHeight, expectidDepth)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)

BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CAbstractBody*>(&parallelepiped));
}

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetDensity()), float(expectedWeight / expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(parallelepiped.GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Parallelepiped Volume = 50.000000 Weight = 6.000000 Density = 0.120000";
	BOOST_CHECK_EQUAL(parallelepiped.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()