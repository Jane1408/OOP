#include "stdafx.h"
#include "Sphere.h"


CSphere::CSphere()
{
}

CSphere::CSphere(double weight, double radius)
	: m_radius(radius)
{
	SetWeight(weight);
	SetVolume();
	SetDensity();
}

CSphere::~CSphere()
{
}

std::string CSphere::GetInfo()
{
	std::string info = "Sphere Volume = ";
	info += std::to_string(GetVolume());
	info += " Weight = ";
	info += std::to_string(GetWeight());
	info += " Density = ";
	info += std::to_string(GetDensity());
	return info;
}

void CSphere::SetVolume()
{
	m_volume = (4 * M_PI * std::pow(m_radius, 3)) / 3;
}
