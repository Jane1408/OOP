#pragma once
#include "AbstractBody.h"
class CCompound :
	public CAbstractBody
{
public:
	CCompound();
	~CCompound();
	void AddBody(CAbstractBody const& otherbody);
	std::string GetInfo() override;
protected:
	void SetWeight(double weight) override;
	void SetVolume(double volume) override;

};

