#include "stdafx.h"
#include "../4.1/Compound.h"
#include "../4.1/Sphere.h"

struct Compound_
{
	std::shared_ptr<CCompound> CompoundBodies = std::make_shared<CCompound>();
};

BOOST_FIXTURE_TEST_SUITE(Compound, Compound_)

BOOST_AUTO_TEST_CASE(is_a_body)
{
	BOOST_CHECK(static_cast<const CAbstractBody*>(CompoundBodies.get()));
}

struct Compound_one_body_ : Compound_
{
	double expectedRadius = 5;
	double expectedVolume = 523.598776;
	double expectedWeight = 100;
	Compound_one_body_()
	{
		CompoundBodies->AddBody(CSphere(expectedWeight, expectedRadius));
	}
};
BOOST_FIXTURE_TEST_SUITE(Compound_one_body, Compound_one_body_)
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetDensity()), float(expectedWeight / expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Compound bodies Volume = 523.598776 Weight = 100.000000 Density = 0.190986";
	BOOST_CHECK_EQUAL(CompoundBodies.get()->GetInfo(), expectedString);
}

struct Compound_two_bodies_ : Compound_one_body_
{
	double expectedVolume = 1047.197552;
	double expectedWeight = 200;
	double addedWeight = 100;
	double addedRadius = 5;
	Compound_two_bodies_()
	{
		CompoundBodies->AddBody(CSphere(addedWeight, addedRadius));
	}
};
BOOST_FIXTURE_TEST_SUITE(Compound_two_bodies, Compound_two_bodies_)
BOOST_AUTO_TEST_CASE(has_a_density)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetDensity()), float(expectedWeight / expectedVolume));
}

BOOST_AUTO_TEST_CASE(has_a_weigth)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetWeight()), float(expectedWeight));
}

BOOST_AUTO_TEST_CASE(has_a_volume)
{
	BOOST_CHECK_EQUAL(float(CompoundBodies.get()->GetVolume()), float(expectedVolume));
}

BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
{
	auto expectedString = "Compound bodies Volume = 1047.197551 Weight = 200.000000 Density = 0.190986";
	BOOST_CHECK_EQUAL(CompoundBodies.get()->GetInfo(), expectedString);
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()