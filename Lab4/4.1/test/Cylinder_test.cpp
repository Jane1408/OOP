#include "stdafx.h"
#include "../4.1/Cylinder.h"

struct Cylinder_
{
	double expectidHeight = 10;
	double expectedRadius = 2;
	double expectedVolume = 125.663705;
	double expectedWeight = 3;
	CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedWeight, expectedRadius, expectidHeight)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)

BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CAbstractBody*>(&cylinder));
}

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetDensity()), float(expectedWeight / expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(cylinder.GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Cylinder Volume = 125.663706 Weight = 3.000000 Density = 0.023873";
	BOOST_CHECK_EQUAL(cylinder.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()