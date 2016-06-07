#include "stdafx.h"
#include "Cylinder.h"


CCylinder::CCylinder(double weight, double radius, double height)
	: m_radius(radius)
	, m_height(height)
{
	SetWeight(weight);
	SetVolume();
	SetDensity();
}


CCylinder::~CCylinder()
{
}

std::string CCylinder::GetInfo()
{
	std::string info = "Cylinder Volume = ";
	info += std::to_string(GetVolume());
	info += " Weight = ";
	info += std::to_string(GetWeight());
	info += " Density = ";
	info += std::to_string(GetDensity());
	return info;
}

void CCylinder::SetVolume()
{
	m_volume = M_PI * std::pow(m_radius, 2) * m_height;
}

