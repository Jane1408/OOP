#include "stdafx.h"
#include "KrasckalRoad.h"


CKrasckalRoad::CKrasckalRoad()
{
}


CKrasckalRoad::~CKrasckalRoad()
{
}

void CKrasckalRoad::SetLandMap(std::string const & fileName)
{
	ReadFromFile(fileName);
	DoKrasckal();
}

int CKrasckalRoad::GetPrice()
{
	return m_price;
}

std::multimap<int, int> CKrasckalRoad::GetAsphaltRoads()
{
	return m_asphaltRoads;
}

void CKrasckalRoad::WriteIntoFile(std::string const & fileName)
{
	std::ofstream output(fileName);

	output << m_price << std::endl;
	for (auto &it : m_asphaltRoads)
	{
		output << it.first << " "<< it.second << std::endl;
	}
}

void CKrasckalRoad::ReadFromFile(std::string const & fileName)
{
	m_towersCount = 0;
	m_edges.clear();
	m_asphaltRoads.clear();
	m_usedVertex.clear();
	m_price = 0;
	std::ifstream input(fileName);
	input >> m_towersCount;
	int roadsCount = 0;
	input >> roadsCount;

	int firstTower = 0;
	int secondTower = 0;
	int weight = 0;
	for (int it = 0; it < roadsCount; ++it)
	{
		input >> firstTower;
		input >> secondTower;
		input >> weight;
		m_edges.insert({ weight, {firstTower, secondTower} });
	}
}

void CKrasckalRoad::DoKrasckal()
{
	for (auto &it : m_edges)
	{
		if ( !CheckLoop(it.second.first, it.second.second))
		{
			m_price += it.first;
			AddNewSet(it.second.first, it.second.second);
			AddAsphaltRoad(it.second.first, it.second.second);
		}
		if (m_usedVertex[0].size() == m_towersCount)
		{
			break;
		}
	}
}

void CKrasckalRoad::AddAsphaltRoad(int firstTown, int secondTown)
{
	if (firstTown > secondTown)
	{
		m_asphaltRoads.insert({ secondTown, firstTown });
	}
	else
	{
		m_asphaltRoads.insert({ firstTown, secondTown });
	}
}

bool CKrasckalRoad::CheckLoop(int first, int second) const
{
	for (auto &it : m_usedVertex)
	{
		if (it.find(first) != it.end() && it.find(second) != it.end())
		{
			return true;
		}

	}
	return false;
}

void CKrasckalRoad::AddNewSet(int first, int second)
{
	bool isNewSet = true;
	for (auto it = m_usedVertex.begin(); it != m_usedVertex.end(); ++it)
	{
		if (it->find(first) != it->end() || it->find(second) != it->end())
		{
			isNewSet = false;
			it->insert(first);
			it->insert(second);
			for (auto it1 = it; it1 != m_usedVertex.end(); ++it1)
			{
				if (it1 != it && (it1->find(first) != it1->end() || it1->find(second) != it1->end()))
				{
					for (auto &vertex : *it1)
					{
						it->insert(vertex);
					}
					m_usedVertex.erase(it1);
					return;
				}
			}
		}
	}
	if (isNewSet)
	{
		m_usedVertex.push_back({ first, second });
	}
}
