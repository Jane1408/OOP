#include "stdafx.h"
#include "../4.1/Cone.h"

struct Cone_
{
	double expectidHeight = 5;
	double expectedRadius = 1;
	double expectedVolume = 5.23598766;
	double expectedWeight = 10;
	CCone cone;
	Cone_()
		: cone(expectedWeight, expectedRadius, expectidHeight)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)

BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CAbstractBody*>(&cone));
}

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(cone.GetDensity()), float(expectedWeight / expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(cone.GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(cone.GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Cone Volume = 5.235988 Weight = 10.000000 Density = 1.909859";
	BOOST_CHECK_EQUAL(cone.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()