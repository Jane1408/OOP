#pragma once

class CBonnieAndClyde
{
public:
	CBonnieAndClyde(std::string const & input);
	void WriteInOutputFile();
	std::pair<int, int> GetNumbersOfBanks() const;
	int GetMaxMoney() const;
private:
	void ReadFromFile(std::string const& input);
	void FindAnswer();

	std::multimap < int, std::pair<int, int> > m_moneyAndDistance;
	std::pair <int, int> m_pairOfBanks;
	int m_maxMoney;
	int m_numOfBanks;
	int m_minDistance;

	int m_firstBank;
	int m_lastBank;
};

