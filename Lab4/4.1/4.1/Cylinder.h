#pragma once
#include "AbstractBody.h"
class CCylinder :
	public CAbstractBody
{
public:
	CCylinder(double weight, double radius, double height);
	~CCylinder();
	std::string GetInfo() override;
protected:
	void SetVolume() override;
private:
	double m_radius;
	double m_height;
};

