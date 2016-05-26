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

	std::vector <std::pair <size_t, size_t>> m_distanceAndMoney;
	std::pair <int, int> m_pairOfBanks;
	int m_maxMoney;
	size_t m_numOfBanks;
	size_t m_minDistance;
};

