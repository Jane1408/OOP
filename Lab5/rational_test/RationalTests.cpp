﻿// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../rational/Rational.h"

const double C_ACCURACY = 10e-15;

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

void VerifyDouble(const CRational & r, double expectedDouble)
{
	BOOST_CHECK_CLOSE(r.ToDouble(), expectedDouble, C_ACCURACY);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
// Возвращает отношение числителя и знаменателя в виде числа double
// Пример использования:
//	CRational r(3, 5)
//	cout << r.ToDouble(); // Должно вывести 0.6
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
	{
		VerifyDouble(CRational(3, 5), 0.6);
		VerifyDouble(CRational(1, 3), 0.33333333333333333);
		VerifyDouble(CRational(0, 3), 0);
		VerifyDouble(CRational(), 0);
		VerifyDouble(CRational(-1, 3), -0.33333333333333333);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
// Указание: см. материалы к лекции
// Пример использования:
//	const CRational r1(3, 5);
//	CRational r2 = -r1; // r2 должно стать -3/5
//	assert(r2.GetNumerator(), -3);
//	assert(r2.GetDenominator(), 5);
//	CRational r3 = +r2; // r3 также равно -3/5
//	assert(r3.GetNumerator(), -3);
//	assert(r3.GetDenominator(), 5);
// Унарный минус возвращает раицональное число без знака
// Унарный плюс возвращает рациональное число, равное текущему
// Реализация не должна допускать операции вроде:
//  -someRational = someOtherRational;
//	+someRational = someOtherRational;
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(has_unary_minus_operator_that_changes_sign_of_a_number)
	{
		const CRational rational(3, 5);
		BOOST_CHECK_NE(std::addressof(-rational), std::addressof(rational));
		VerifyRational(-rational, -3, 5);
	}

	BOOST_AUTO_TEST_CASE(has_unary_plus_operator_that_returns_a_copy)
	{
		const CRational rational(3, 5);
		BOOST_CHECK_NE(std::addressof(+rational), std::addressof(rational));
		VerifyRational(+rational, 3, 5);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(summ_rational_values)
	{

		VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
		VerifyRational(CRational(1, 2) + 1, 3, 2);
		VerifyRational(1 + CRational(1, 2), 3, 2);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////
	BOOST_AUTO_TEST_CASE(substraction_rational_values)
	{
		VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
		VerifyRational(CRational(1, 2) - 1, -1, 2);
		VerifyRational(1 - CRational(1, 2), 1, 2);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(can_be_increased_by_a_rational_number)
	{
		CRational lhs(1, 2);
		lhs += CRational(1, 6);
		VerifyRational(lhs, 2, 3);
	}
	

	BOOST_AUTO_TEST_CASE(can_be_increased_by_an_integer_number)
	{
		CRational lhs(1, 2);
		lhs += 1;
		VerifyRational(lhs, 3, 2);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(can_be_decreased_by_a_rational_number)
	{
		CRational lhs(1, 2);
		lhs -= CRational(1, 6);
		VerifyRational(lhs, 1, 3);
	}


	BOOST_AUTO_TEST_CASE(can_be_decreased_by_an_integer_number)
	{
		CRational lhs(1, 2);
		lhs -= 1;
		VerifyRational(lhs, -1, 2);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	(7*2) / 3     = (14/3)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(multiply_rational_values)
	{
		VerifyRational(CRational(1, 2) * CRational(2, 3), 1, 3);
		VerifyRational(CRational(1, 2) * -3, -3, 2);
		VerifyRational(CRational(7, 3) * 2, 14, 3);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(division_rational_values)
	{
		VerifyRational(CRational(1, 2) / CRational(2, 3), 3, 4);
		VerifyRational(CRational(1, 2) / 5, 1, 10);
		VerifyRational(7 / CRational(2 , 3), 21, 2);
	}



//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////


	BOOST_AUTO_TEST_CASE(multiply_rational_value_on_something)
	{
		VerifyRational(CRational(1, 2) *= CRational(2, 3), 1, 3);
		VerifyRational(CRational(1, 2) *= 3, 3, 2);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(division_rational_value_on_something)
	{
		VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
		VerifyRational(CRational(1, 2) /= 3, 1, 6);
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(check_logic_operators)
	{
		BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
		BOOST_CHECK(!(CRational(1, 2) == CRational(1, 7)));
		BOOST_CHECK(CRational(4, 1) == 4);
		BOOST_CHECK(!(CRational(4, 1) == 5));
		BOOST_CHECK(3 == CRational(3, 1));
		BOOST_CHECK(!(3 == CRational(3, 3)));
		BOOST_CHECK(CRational(1, 2) != CRational(2, 3));
		BOOST_CHECK(!(CRational(1, 2) != CRational(2, 4)));
		BOOST_CHECK(CRational(1, 2) != 7);
		BOOST_CHECK(3 != CRational(2, 3));
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////

	BOOST_AUTO_TEST_CASE(check_compare_operators)
	{
		BOOST_CHECK(CRational(1, 2) >= CRational(1, 3));
		//BOOST_CHECK(!(CRational(1, 2) <= CRational(1, 3)));
		//BOOST_CHECK(CRational(3, 1) > 2);
		//BOOST_CHECK(!(CRational(3, 1) < 2));
		/*BOOST_CHECK(CRational(1, 2) < 7);
		BOOST_CHECK(!(CRational(1, 2) > 7));
		*///BOOST_CHECK(3 <= CRational(7, 2));
		//BOOST_CHECK(!(3 >= CRational(8, 2)));
	}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE_END()
