#include "stdafx.h"
#include "AbstractBody.h"


CAbstractBody::CAbstractBody()
	: m_density(0)
	, m_weight(0)
	, m_volume(0)
{
}


CAbstractBody::~CAbstractBody()
{
}

double CAbstractBody::GetWeight() const
{
	return m_weight;
}

double CAbstractBody::GetDensity() const
{
	return m_density;
}

double CAbstractBody::GetVolume() const
{
	return m_volume;
}


void CAbstractBody::SetWeight(double weight)
{
	m_weight = weight;
}

void CAbstractBody::SetDensity()
{
	m_density = GetWeight() / GetVolume();
}

void CAbstractBody::SetVolume()
{
}

void CAbstractBody::SetVolume(double volume)
{
	m_volume = volume;
}
