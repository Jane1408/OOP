#include "stdafx.h"
#include "../14.1/BonnieAndClyde.h"

BOOST_AUTO_TEST_SUITE(Bonnie_and_Clyde_testing)

BOOST_AUTO_TEST_CASE(when_input_file_is_empty)
{
	CBonnieAndClyde testBAC1("./testing_files/input2.txt");
	BOOST_CHECK_EQUAL(testBAC1.GetMaxMoney(), -1);
	BOOST_CHECK_EQUAL(testBAC1.GetNumbersOfBanks().first, -1);
	BOOST_CHECK_EQUAL(testBAC1.GetNumbersOfBanks().second, -1);
};

BOOST_AUTO_TEST_CASE(when_input_file_is_correct)
{
	CBonnieAndClyde testBAC("./testing_files/input1.txt");
	BOOST_CHECK_EQUAL(testBAC.GetMaxMoney(), 11);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().first, 3);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().second, 5);
};

BOOST_AUTO_TEST_CASE(when_input_file_is_correct_but_is_no_decision)
{
	CBonnieAndClyde testBAC("./testing_files/input3.txt");
	BOOST_CHECK_EQUAL(testBAC.GetMaxMoney(), -1);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().first, -1);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().second, -1);
};

BOOST_AUTO_TEST_CASE(when_input_file_is_correct_check_correct_of_algorithm)
{
	CBonnieAndClyde testBAC("./testing_files/input4.txt");
	BOOST_CHECK_EQUAL(testBAC.GetMaxMoney(), 13);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().first, 4);
	BOOST_CHECK_EQUAL(testBAC.GetNumbersOfBanks().second, 2);
};
BOOST_AUTO_TEST_SUITE_END();