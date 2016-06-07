#pragma once
#include "AbstractBody.h"
class CParallelepiped :
	public CAbstractBody
{
public:
	CParallelepiped(double weight, double width, double height, double depth);
	~CParallelepiped();
	std::string GetInfo() override;
protected:
	void SetVolume() override;
private:
	double m_width;
	double	m_height;
	double	m_depth;
};

