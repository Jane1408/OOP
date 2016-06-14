#include "stdafx.h"
#include "..\11.1\TriangleAndPoint.h"

BOOST_AUTO_TEST_SUITE(Triangle_and_point_testing)

BOOST_AUTO_TEST_CASE(when_input_file_is_empty)
{
	CTriangleAndPoint test("./testing_files/input1.txt");
	BOOST_CHECK(!test.GetAnswer());
};

BOOST_AUTO_TEST_CASE(when_point_in_triangle)
{
	CTriangleAndPoint test("./testing_files/input2.txt");
	BOOST_CHECK(test.GetAnswer());
};

BOOST_AUTO_TEST_CASE(when_point_out_of_triangle)
{
	CTriangleAndPoint test("./testing_files/input3.txt");
	BOOST_CHECK(!test.GetAnswer());
};

BOOST_AUTO_TEST_CASE(when_input_file_is_max_size)
{
	CTriangleAndPoint test("./testing_files/input4.txt");
	BOOST_CHECK(!test.GetAnswer());
};

BOOST_AUTO_TEST_SUITE_END();