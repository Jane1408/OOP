#include "stdafx.h"
#include "Compound.h"


CCompound::CCompound()
{
}


CCompound::~CCompound()
{
}

void CCompound::AddBody(CAbstractBody const & otherbody)
{
	SetWeight(otherbody.GetWeight());
	SetVolume(otherbody.GetVolume());
	SetDensity();
}

std::string CCompound::GetInfo()
{
	std::string info = "Compound bodies Volume = ";
	info += std::to_string(GetVolume());
	info += " Weight = ";
	info += std::to_string(GetWeight());
	info += " Density = ";
	info += std::to_string(GetDensity());
	return info;
}

void CCompound::SetWeight(double weight)
{
	m_weight += weight;
}

void CCompound::SetVolume(double volume)
{
	m_volume += volume;
}
