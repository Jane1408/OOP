#include "stdafx.h"
#include "ComandHandler.h"


CComandHandler::CComandHandler()
{
}


CComandHandler::~CComandHandler()
{
}



void CComandHandler::SetBody(std::string const & command)
{
	auto body = GetCommand(command);
	if (body != nullptr)
	{
		m_bodies.push_back(body);
	}
}

void CComandHandler::DisplayInfo()
{
	double maxWeight = 0;
	double minWeigthInWater = std::numeric_limits<double>::infinity();
	double valueInWater = 0;
	for (auto &it : m_bodies)
	{
		if (maxWeight < it->GetWeight())
		{
			maxWeight = it->GetWeight();
			m_maxWeightBody = it.get();
		}
			maxWeight = (maxWeight < it->GetWeight()) ? it->GetWeight() : maxWeight;
		valueInWater = (it->GetDensity() - WATER_DENSITY) * G * it->GetVolume();
		if (minWeigthInWater > valueInWater)
		{
			minWeigthInWater = valueInWater;
			m_ligthWaterBody = it.get();
		}
	}
	std::cout << "Body with maximum weight: " << std::endl;
	std::cout << m_maxWeightBody->GetInfo() << std::endl;
	std::cout << "The lightest body in water: " << std::endl;
	std::cout << m_ligthWaterBody->GetInfo() << std::endl;

}

std::shared_ptr<CAbstractBody> CComandHandler::GetCommand(std::string const & command)
{
	std::shared_ptr<CAbstractBody> body;
	if (command == "cone")
	{
		body = std::make_shared<CCone>(CCone(GetValue("weigth"), GetValue("radius"), GetValue("heigth")));
	}
	else if (command == "cylinder")
	{
		body = std::make_shared<CCylinder>(CCylinder(GetValue("weigth"), GetValue("radius"), GetValue("heigth")));
	}
	else if (command == "parallelepiped")
	{
		body = std::make_shared<CParallelepiped>(CParallelepiped(GetValue("weigth"), GetValue("width"), GetValue("heigth"), GetValue("depth")));
	}
	else if (command == "sphere")
	{
		body = std::make_shared<CSphere>(CSphere(GetValue("weigth"), GetValue("radius")));
	}
	else if (command == "compound")
	{
		body = std::make_shared<CCompound>(MakeCompoundBodies());
	}
	else if (command == "help")
	{
		DisplayHelp();
		body = nullptr;
	}
	else
	{
		std::cout << "Invalid shape" << std::endl;
		body = nullptr;
	}
	return body;
}

void CComandHandler::DisplayHelp()
{
	std::cout << "Enter name of body that you want to add" << std::endl;
	std::cout << "Bodies: <sphere> <cone> <cylinder> <parallelepiped>" << std::endl;
	std::cout << "use <compound> for add compound bodies" << std::endl;
}

CCompound CComandHandler::MakeCompoundBodies()
{
	CCompound compound;
	std::string command;
	std::cout << "Enter name of body to compound (enter <end> to exit): " << std::endl;
	for (;;)
	{
		std::cout << ">>";
		std::cin >> command;
		if (command == "end")
		{
			break;
		}
		auto body = GetCommand(command);
		if (body != nullptr)
		{
			compound.AddBody(*body);
		}
	}
	return compound;
}

double CComandHandler::GetValue(std::string const & info)
{
	double number;
	std::cout << info << " = ";
	std::cin >> number;
	while (number <= 0)
	{
		std::cout << "Invalid value" << std::endl;
		std::cout << info << " = ";
		std::cin >> number;
	}
	return number;
	
}
