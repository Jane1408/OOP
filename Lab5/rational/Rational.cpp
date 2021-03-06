﻿#include "stdafx.h"
#include "Rational.h"
#include <utility>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble() const
{
	return double(m_numerator) / double(m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+() const
{
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
CRational operator+ (CRational const& first, CRational const& second)
{
	auto numerator = (first.GetNumerator()* second.GetDenominator()) + (second.GetNumerator() * first.GetDenominator());
	auto denominator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////


CRational operator- (CRational const& first, CRational const& second)
{
	return first + -second;

}

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator+=(CRational const & other)
{
	m_numerator = GetNumerator() * other.GetDenominator() + other.GetNumerator() * GetDenominator();
	m_denominator = other.GetDenominator() * GetDenominator();
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator-=(CRational const & other)
{
	return *this += -other;

}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////


CRational operator *(CRational const& first, CRational const& second) 
{
	auto numerator = first.GetNumerator() * second.GetNumerator();
	auto denominator = first.GetDenominator() * second.GetDenominator();
	return CRational(numerator, denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////

CRational operator/ (CRational const& first, CRational const& second) 
{
	return first * CRational(second.GetDenominator(), second.GetNumerator());

}
//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator*= (const CRational& other)
{
	m_numerator *= other.GetNumerator();
	m_denominator *= other.GetDenominator();
	Normalize();
	return *this;
}

CRational CRational::operator*= (int value)
{
	return *this * CRational(value, 1);

}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator/= (const CRational& other)
{
	return *this *= CRational(other.GetDenominator(), other.GetNumerator());

}

CRational CRational::operator/= (int value)
{
	return *this *= CRational(1, value);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
bool CRational::operator== (const CRational& other)
{
	return (GetNumerator() == other.GetNumerator() && GetDenominator() == other.GetDenominator());
}

bool CRational::operator== (int value)
{
	return *this == CRational(value, 1);
}

bool operator== (int  first, const CRational& second)
{
	return CRational(first, 1) == second;
}

bool CRational::operator!= (const CRational& other)
{
	return !(*this == other);

}

bool CRational::operator!= (int value)
{
	return !(*this == CRational(value, 1));
}

bool operator!= (int first, const CRational& second)
{
	return !(CRational(first, 1) == second);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const CRational::operator< (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) < (other.GetNumerator() * m_denominator));
}

bool const CRational::operator< (int other)
{
	return !(*this >= CRational(other));
}

bool const operator< (int first, const CRational& second)
{
	return !(CRational(first) >= second);
}

bool const CRational::operator> (const CRational& other)
{
	return !(*this <= other);
}

bool const CRational::operator> (int other)
{
	return !(*this <= CRational(other));
}

bool const operator> (int first, const CRational& second)
{
	return !(CRational(first, 1) <= CRational(second));
}

bool const CRational::operator<= (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) <= (other.GetNumerator() * m_denominator));
}

bool const CRational::operator<= (int other)
{
	return !(*this > CRational(other));
}

bool const operator<= (int first, const CRational& second)
{
	return !(CRational(first) > second);
}

bool const CRational::operator>= (const CRational& other)
{
	return !(*this < CRational(other));
}

bool const CRational::operator>= (int other)
{
	return !(*this < CRational(other));
}

bool const operator>= (int first, const CRational& second)
{ 
	return !(CRational(first) < second);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
