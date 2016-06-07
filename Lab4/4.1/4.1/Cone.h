#pragma once
#include "AbstractBody.h"
class CCone :
	public CAbstractBody
{
public:
	CCone(double weight, double radius, double height);
	~CCone();
	std::string GetInfo() override;
protected:
	void SetVolume() override;
private:
	double m_radius;
	double m_height;
};

