#pragma once
#include "AbstractBody.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"
#include "Compound.h"

static const double WATER_DENSITY = 1000;
static const double G = 9.78;

class CComandHandler
{
public:
	CComandHandler();
	~CComandHandler();
	
	void SetBody(std::string const& command);
	void DisplayInfo();

private:
	void DisplayHelp();
	CCompound MakeCompoundBodies();
	double GetValue(std::string const& info);
	std::shared_ptr<CAbstractBody> GetCommand(std::string const& command);
	std::vector <std::shared_ptr<CAbstractBody>> m_bodies;

	CAbstractBody *m_maxWeightBody = nullptr;
	CAbstractBody *m_ligthWaterBody = nullptr;
};

