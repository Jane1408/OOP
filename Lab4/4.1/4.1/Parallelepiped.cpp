#include "stdafx.h"
#include "Parallelepiped.h"

CParallelepiped::CParallelepiped(double weight, double width, double height, double depth)
	: m_width(width)
	, m_height(height)
	, m_depth(depth)
{
	SetWeight(weight);
	SetVolume();
	SetDensity();
}

CParallelepiped::~CParallelepiped()
{
}

std::string CParallelepiped::GetInfo()
{
	std::string info = "Parallelepiped Volume = ";
	info += std::to_string(GetVolume());
	info += " Weight = ";
	info += std::to_string(GetWeight());
	info += " Density = ";
	info += std::to_string(GetDensity());
	return info;
}

void CParallelepiped::SetVolume()
{
	m_volume = m_width * m_height * m_depth;
}
