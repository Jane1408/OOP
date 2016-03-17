#include "stdafx.h"
#include "..\Lab2.1\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> emptyVector;
	ProcessVector(emptyVector);
	BOOST_CHECK(emptyVector.empty());
}

BOOST_AUTO_TEST_CASE(does_not_change_vector_containing_same_numbers)
{
	vector<double> numbers = {3, 3, 3};
	auto copy(numbers); // аналог vector<double> copy(numbers);
	ProcessVector(numbers);
	BOOST_CHECK(numbers == copy);
}

// при обработке вектора с несколькими отрицательными элементами
BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_several_positive_elements)
// должен умножить это число на максимальный и разделить на минимальный элементы вектора
BOOST_AUTO_TEST_CASE(should_multiply_this_number_by_max_and_divided_by_min_element)
{
	vector<double> numbers = { -1, 1, -2, 3 };
	ProcessVector(numbers);

	const double max = 3;
	const double min = -2;
	const double multiplyValue = max / min;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 * multiplyValue), (1 * multiplyValue), (-2 * multiplyValue), (3 * multiplyValue) }
	));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()