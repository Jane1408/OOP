#include "stdafx.h"
#include "BonnieAndClyde.h"
#include <algorithm>


CBonnieAndClyde::CBonnieAndClyde(std::string const & input)
	: m_maxMoney(-1)
	, m_pairOfBanks({ -1, -1 })
{
	ReadFromFile(input);
	FindAnswer();
}

void CBonnieAndClyde::WriteInOutputFile()
{
	std::ofstream outputFile("output.txt");
	outputFile << m_maxMoney << std::endl;
	outputFile << m_pairOfBanks.first << " " << m_pairOfBanks.second;
}

void CBonnieAndClyde::ReadFromFile(std::string const & input)
{
	std::ifstream inputFile(input);
	inputFile >> m_numOfBanks;
	inputFile >> m_minDistance;
	int money;
	int distance;
	for (int i = 1; i <= m_numOfBanks; ++i)
	{
		inputFile >> distance;
		inputFile >> money;
		m_moneyAndDistance.insert({ money, {distance, i} });
	}
	inputFile.close();
}

void CBonnieAndClyde::FindAnswer()
{
	auto rangeBegin = m_moneyAndDistance.rbegin();
	auto rangeEnd = m_moneyAndDistance.rend();
	for (auto it1 = rangeBegin; it1 != rangeEnd; ++it1)
	{
		for (auto it2 = it1; it2 != rangeEnd; ++it2)
		{
			if (std::abs((it1->second.first) - (it2->second.first)) >= m_minDistance)
			{
				if (m_maxMoney < (it1->first + it2->first))
				{
					m_pairOfBanks = { it1->second.second , it2->second.second };
					m_maxMoney = it1->first + it2->first;
					rangeEnd = it2;
					break;
				}
			}
		}
	}
}

std::pair<int, int> CBonnieAndClyde::GetNumbersOfBanks() const
{
	return m_pairOfBanks;
}

int CBonnieAndClyde::GetMaxMoney() const
{
	return m_maxMoney;
}

