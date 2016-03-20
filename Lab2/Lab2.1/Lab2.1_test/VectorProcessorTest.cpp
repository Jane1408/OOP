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
BOOST_AUTO_TEST_CASE(should_not_change_vector_containing_same_numbers)
{
	vector<double> numbers = {3, 3, 3};
	auto copy(numbers); 
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

BOOST_AUTO_TEST_CASE(should_not_change_vector_containing_one_element)
{
	vector<double> numbers = { 3 };
	auto copy(numbers); 
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_the_maximum_and_minimum_element_of_the_vector_are_different)
BOOST_AUTO_TEST_SUITE(when_minimum_element_equal_to_zero)
BOOST_AUTO_TEST_CASE(should_not_divide_elements_by_minimum_element)
{
	vector<double> numbers = { 0, 1, 2, 3};
	ProcessVector(numbers);
	const double max = 3;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (0 * max), (1 * max), (2 * max), (3 * max) }
	));
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(when_minimum_element_is_negative_and_maximum_element_is_positive)
BOOST_AUTO_TEST_CASE(should_change_the_signs_of_the_elements_on_the_opposite_signs)
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
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_minimum_element_is_negative_and_maximum_element_is_negative)
BOOST_AUTO_TEST_CASE(should_not_change_the_signs_of_the_elements_and_all_elements_will_be_negative)
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
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(when_minimum_element_is_positive_and_maximum_element_is_positive)
BOOST_AUTO_TEST_CASE(should_not_change_the_signs_of_the_elements_and_all_elements_will_be_positive)
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