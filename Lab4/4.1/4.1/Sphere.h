#pragma once
#include "AbstractBody.h"
class CSphere :
	public CAbstractBody
{
public:
	CSphere();
	CSphere(double weight, double radius);
	~CSphere();
	std::string GetInfo() override;
protected:
	void SetVolume() override;

private:

	double m_radius;
};

