#include "stdafx.h"
#include "Cone.h"


CCone::CCone(double weight, double radius, double height)
	: m_radius(radius)
	, m_height(height)
{
	SetWeight(weight);
	SetVolume();
	SetDensity();
}


CCone::~CCone()
{
}

std::string CCone::GetInfo()
{
	std::string info = "Cone Volume = ";
	info += std::to_string(GetVolume());
	info += " Weight = ";
	info += std::to_string(GetWeight());
	info += " Density = ";
	info += std::to_string(GetDensity());
	return info;
}

void CCone::SetVolume()
{
	m_volume = (M_PI * m_height * std::pow(m_radius, 2)) / 3;
}

