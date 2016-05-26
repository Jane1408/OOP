#include "stdafx.h"
#include "BonnieAndClyde.h"


CBonnieAndClyde::CBonnieAndClyde(std::string const & input)
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
	size_t money;
	size_t distance;
	for (size_t i = 0; i < m_numOfBanks; ++i)
	{
		inputFile >> distance;
		inputFile >> money;
		m_distanceAndMoney.push_back({ distance, money });
	}
	inputFile.close();
}

void CBonnieAndClyde::FindAnswer()
{
	m_maxMoney = -1;
	m_pairOfBanks = { -1, -1 };
	int moneyInTwoBanks = 0;
	for (size_t i = 0; i < m_distanceAndMoney.size(); ++i)
	{
		for (size_t j = i; j < m_distanceAndMoney.size(); ++j)
		{
			if ((m_distanceAndMoney[i].first + m_minDistance) <= m_distanceAndMoney[j].first)
			{
				moneyInTwoBanks = m_distanceAndMoney[i].second + m_distanceAndMoney[j].second;
				if (m_maxMoney < moneyInTwoBanks)
				{
					m_maxMoney = moneyInTwoBanks;
					m_pairOfBanks = { i + 1, j + 1 };
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

