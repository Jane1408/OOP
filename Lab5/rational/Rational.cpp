#include "stdafx.h"
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
const CRational CRational::operator+ (const CRational& other) const
{
	auto numerator = (m_numerator * other.GetDenominator()) + (other.GetNumerator() * m_denominator);
	auto denominator = m_denominator * other.GetDenominator();
	return CRational(numerator, denominator);
}

CRational operator+ (int first, const CRational& second)
{
	auto numerator = (first * second.GetDenominator()) + (second.GetNumerator());
	auto denominator = second.GetDenominator();
	return CRational(numerator, denominator);
}

const CRational CRational::operator+ (int const& value) const
{
	auto numerator = (m_numerator + (value * m_denominator));
	return CRational(numerator, m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator- (const CRational& other) const
{
	auto numerator = (m_numerator * other.GetDenominator()) - (other.GetNumerator() * m_denominator);
	auto denominator = m_denominator * other.GetDenominator();
	return CRational(numerator, denominator);
}

CRational operator- (int first, const CRational& second)
{
	auto numerator = (first * second.GetDenominator()) - (second.GetNumerator());
	auto denominator = second.GetDenominator();
	return CRational(numerator, denominator);
}

const CRational CRational::operator- (int const& value) const
{
	auto numerator = (m_numerator - (value * m_denominator));
	return CRational(numerator, m_denominator);
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
	m_numerator = GetNumerator() * other.GetDenominator() - other.GetNumerator() * GetDenominator();
	m_denominator = other.GetDenominator() * GetDenominator();
	Normalize();
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////

const CRational CRational::operator *(CRational const& other) const
{
	auto numerator = m_numerator * other.GetNumerator();
	auto denominator = m_denominator * other.GetDenominator();
	return CRational(numerator, denominator);
}

CRational operator* (int first, const CRational& second)
{
	return CRational(second.GetNumerator() * first, second.GetDenominator());
}

const CRational CRational::operator* (int const& value) const
{
	return CRational(m_numerator * value, m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////
const CRational CRational::operator/ (CRational const& other) const
{
	auto numerator = m_numerator * other.GetDenominator();
	auto denominator = m_denominator * other.GetNumerator();
	return CRational(numerator, denominator);
}

CRational operator/ (int first, const CRational& second)
{
	return CRational(second.GetDenominator()  * first, second.GetNumerator());
}

const CRational CRational::operator/ (int const& value) const
{
	return CRational(m_numerator, m_denominator * value);
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

CRational CRational::operator*= (int const& value)
{
	m_numerator *= value;
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
CRational CRational::operator/= (const CRational& other)
{
	m_numerator *= other.GetDenominator();
	m_denominator *= other.GetNumerator();
	Normalize();
	return *this;
}

CRational CRational::operator/= (int const& value)
{
	m_denominator *= value;
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////
bool CRational::operator== (const CRational& other)
{
	return (GetNumerator() == other.GetNumerator() && GetDenominator() == other.GetDenominator());
}

bool CRational::operator== (int const& value)
{
	return (GetNumerator() == value && GetDenominator() == 1);
}

bool operator== (int const& first, const CRational& second)
{
	return (first == second.GetNumerator()) && (second.GetDenominator() == 1);
}

bool CRational::operator!= (const CRational& other)
{
	return (GetNumerator() != other.GetNumerator() || GetDenominator() != other.GetDenominator());
}

bool CRational::operator!= (int const& value)
{
	return (GetNumerator() != value || GetDenominator() != 1);
}

bool operator!= (int const& first, const CRational& second)
{
	return (first != second.GetNumerator()) || (second.GetDenominator() != 1);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const CRational::operator< (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) < (other.GetNumerator() * m_denominator));
}

bool const CRational::operator< (const int& other)
{
	return (m_numerator < (other * m_denominator));
}

bool const operator< (const int& first, const CRational& second)
{
	return ((first * second.GetDenominator()) < (second.GetNumerator()));
}

bool const CRational::operator> (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) > (other.GetNumerator() * m_denominator));
}

bool const CRational::operator> (const int& other)
{
	return (m_numerator > (other * m_denominator));
}

bool const operator> (const int& first, const CRational& second)
{
	return ((first * second.GetDenominator()) > (second.GetNumerator()));
}

bool const CRational::operator<= (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) <= (other.GetNumerator() * m_denominator));
}

bool const CRational::operator<= (const int& other)
{
	return (m_numerator <= (other * m_denominator));
}

bool const operator<= (const int& first, const CRational& second)
{
	return ((first * second.GetDenominator()) <= (second.GetNumerator()));
}

bool const CRational::operator>= (const CRational& other)
{
	return ((m_numerator * other.GetDenominator()) >= (other.GetNumerator() * m_denominator));
}

bool const CRational::operator>= (const int& other)
{
	return (m_numerator >= (other * m_denominator));
}

bool const operator>= (const int& first, const CRational& second)
{
	return ((first * second.GetDenominator()) >= (second.GetNumerator()));
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
