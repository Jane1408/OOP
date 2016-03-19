#include "stdafx.h"
#include "..\Lab2.1\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

BOOST_AUTO_TEST_SUITE(when_vector_is_empty)
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_min_element_equal_to_max)
BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_same_numbers)
{
	vector<double> numbers = {3, 3, 3};
	auto copy(numbers); 
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_one_element)
{
	vector<double> numbers = { 3 };
	auto copy(numbers); 
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(min_and_max_elements_of_vector_are_vary)
BOOST_AUTO_TEST_SUITE(when_min_element_equal_zero)
BOOST_AUTO_TEST_CASE(min_element_equal_zero)
{
	vector<double> numbers = { 0, 1, 2, 3};
	ProcessVector(numbers);
	const double max = 3;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (0 * max), (1 * max), (2 * max), (3 * max) }
	));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_min_element_not_equal_zero)
BOOST_AUTO_TEST_CASE(min_element_negative_and_max_element_positive)
{
	vector<double> numbers = { -1, -2, 2, 1 };
	ProcessVector(numbers);
	const double max = 2;
	const double min = -2;
	const double multiplier = max / min;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 * multiplier), (-2 * multiplier), (2 * multiplier), (1 * multiplier) }
	));
}

BOOST_AUTO_TEST_CASE(min_element_negative_and_max_element_negative)
{
	vector<double> numbers = { -1, -2, -3, -4 };
	ProcessVector(numbers);
	const double max = -1;
	const double min = -4;
	const double multiplier = max / min;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 * multiplier), (-2 * multiplier), (-3 * multiplier), (-4 * multiplier) }
	));
}

BOOST_AUTO_TEST_CASE(min_element_positive_and_max_element_positive)
{
	vector<double> numbers = { 1, 2, 3, 4 };
	ProcessVector(numbers);
	const double max = 4;
	const double min = 1;
	const double multiplier = max / min;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (1 * multiplier), (2 * multiplier), (3 * multiplier), (4 * multiplier) }
	));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()