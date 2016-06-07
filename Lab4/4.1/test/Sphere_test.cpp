#include "stdafx.h"
#include "../4.1/Sphere.h"

struct Sphere_
{
	double expectedRadius = 5;
	double expectedVolume = 523.598776;
	double expectedWeight = 100;
	CSphere sphere;
	Sphere_()
		: sphere(expectedWeight, expectedRadius)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Sphere, Sphere_)

BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CAbstractBody*>(&sphere));
}

BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(sphere.GetDensity()), float(expectedWeight/ expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(sphere.GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(sphere.GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Sphere Volume = 523.598776 Weight = 100.000000 Density = 0.190986";
	BOOST_CHECK_EQUAL(sphere.GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()