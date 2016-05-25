#include "stdafx.h"
#include "../13.2/KMP.h"

using namespace std;

bool CheckEqualVectors(std::vector <std::pair<size_t, size_t>> const& first, std::vector <std::pair<size_t, size_t>> const& second)
{
	if (first.size() != second.size())
	{
		return false;
	}
	for (size_t i = 0; i < first.size(); ++i)
	{
		if (first[i].first != second[i].first || first[i].second != second[i].second)
		{
			return false;
		}
	}
	return true;
}

struct KMP
{
	CKMP kmp_test;
};

BOOST_FIXTURE_TEST_SUITE(testing_kmp_string, KMP);

	BOOST_AUTO_TEST_CASE(when_input_file_has_several_occurrences_of_word)
	{
		kmp_test.DoAlgorithmKMP("./test_files/input1.txt");
		std::vector <std::pair<size_t, size_t>> result = { {1,1}, {1,14}, {2,6} };
		auto test = kmp_test.GetResults();
		BOOST_CHECK(CheckEqualVectors(result, kmp_test.GetResults()));
	}

	BOOST_AUTO_TEST_CASE(when_input_file_has_several_occurrences_of_frase)
	{
		kmp_test.DoAlgorithmKMP("./test_files/input2.txt");
		std::vector <std::pair<size_t, size_t>> result = { { 2,1 }, {4, 13} };
		BOOST_CHECK(CheckEqualVectors(result, kmp_test.GetResults()));
	}

	BOOST_AUTO_TEST_CASE(when_input_file_is_empty)
	{
		kmp_test.DoAlgorithmKMP("./test_files/input3.txt");
		BOOST_CHECK(kmp_test.GetResults().empty());
	}

	BOOST_AUTO_TEST_CASE(when_text_file_is_empty)
	{
		kmp_test.DoAlgorithmKMP("./test_files/input4.txt");
		BOOST_CHECK(kmp_test.GetResults().empty());
	}

BOOST_AUTO_TEST_SUITE_END();