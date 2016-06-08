#include "stdafx.h"
#include "../MyList/MyList.h"

struct empty_my_list
{
	MyList<int> list;
};

BOOST_FIXTURE_TEST_SUITE(testing_empty_list, empty_my_list)

BOOST_AUTO_TEST_CASE(list_must_be_empty)
{
	BOOST_CHECK_EQUAL(list.size(), 0);
}
BOOST_AUTO_TEST_CASE(after_adding_element_list_size_must_be_one)
{
	list.PushBack(1);
	BOOST_CHECK_EQUAL(list.size(), 1);
}
BOOST_AUTO_TEST_SUITE_END()

struct my_list
{
	my_list()
	{
		list.PushBack(1);
		list.PushBack(2);
		list.PushBack(3);
		list.PushBack(4);
		list.PushBack(5);
	}
	MyList<int> list;

};

BOOST_FIXTURE_TEST_SUITE(testing_list, my_list)
BOOST_AUTO_TEST_CASE(list_size_must_be_5)
{
	BOOST_CHECK_EQUAL(list.size(), 5);
}
BOOST_AUTO_TEST_CASE(first_list_element_must_be_1)
{
	BOOST_CHECK_EQUAL(*list.begin(), 1);
}
BOOST_AUTO_TEST_CASE(last_list_element_must_be_5)
{
	BOOST_CHECK_EQUAL(*list.rbegin(), 5);
}
BOOST_AUTO_TEST_CASE(after_delete_second_element_second_element_will_be_third)
{
	auto iter = ++list.begin();
	BOOST_CHECK_EQUAL(*iter, 2);
	list.Erase(iter);
	BOOST_CHECK_EQUAL(*iter, 3);
}
BOOST_AUTO_TEST_CASE(after_insert_element_in_second_position_it_will_be_new_value)
{
	auto iter = ++list.begin();
	BOOST_CHECK_EQUAL(*iter, 2);
	list.Insert(iter, 8);
	BOOST_CHECK_EQUAL(*iter, 8);
}
BOOST_AUTO_TEST_CASE(if_push_back_new_element_last_will_be_new_value)
{
	list.PushBack(8);
	BOOST_CHECK_EQUAL(list.size(), 6);
	BOOST_CHECK_EQUAL(*list.rbegin(), 8);
}
BOOST_AUTO_TEST_CASE(if_push_front_new_element_first_will_be_new_value)
{
	list.PushFront(8);
	BOOST_CHECK_EQUAL(list.size(), 6);
	BOOST_CHECK_EQUAL(*list.begin(), 8);
}
BOOST_AUTO_TEST_CASE(copy_this_list_in_other)
{
	MyList<int> newList = list;
	BOOST_CHECK_EQUAL(list.size(), 5);
	BOOST_CHECK_EQUAL(*list.begin(), 1);
	BOOST_CHECK_EQUAL(*list.rbegin(), 5);

	BOOST_CHECK_EQUAL(newList.size(), 5);
	BOOST_CHECK_EQUAL(*newList.begin(), 1);
	BOOST_CHECK_EQUAL(*newList.rbegin(), 5);

	const MyList<int> constList = list;
	for (int &i : constList)
	{
		++i;
	}
	auto it = constList.begin();
	BOOST_CHECK_EQUAL(*it, 2);
}
BOOST_AUTO_TEST_SUITE_END()
