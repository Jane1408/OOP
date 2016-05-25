#include "stdafx.h"
#include "KMP.h"
#include <fstream>

CKMP::CKMP()
	: m_lineNumber(1)
{
	
}

void CKMP::DoAlgorithmKMP(std::string const & input)
{
	std::string textFile;
	std::ifstream inputFile(input);
	std::getline(inputFile, m_needle);
	std::getline(inputFile, textFile);
	inputFile.close();
	FindStringInFile(textFile);
}

void CKMP::FindStringInFile(std::string const & textFile)
{
	std::ifstream inputText(textFile);
	std::string line;

	while (std::getline(inputText, line))
	{
		m_positions = Find(line);
		for (auto &it : m_positions)
		{
			m_result.push_back({ m_lineNumber, it });
		}
		++m_lineNumber;
	}
	inputText.close();
}

void CKMP::WriteIntoOutputFile()
{
	std::ofstream outputFile("output.txt");
	for (auto &it : m_result)
	{
		outputFile << it.first << " " << it.second << std::endl;
	}
	outputFile.close();
}

std::vector<std::pair<size_t, size_t>> CKMP::GetResults()
{
	return m_result;
}

std::vector<int> CKMP::GetSearchPrefixFunctions()
{
	size_t x = 0;
	int y = 0;
	std::vector<int> result;
	result.resize(m_needle.size() + 1, 0);
	result[0] = -1;
	while (x < m_needle.size()) 
	{
		while ((y > -1) && (m_needle[x] != m_needle[y]))
		{
			y = result[y];
		}
		++x;
		++y;
		if (m_needle[x] == m_needle[y])
		{
			result[x] = result[y];
		}
		else
		{
			result[x] = y;
		}
	}
	return result;
}

std::vector<size_t> CKMP::Find(std::string const& text)
{
	size_t x = 0;
	int y = 0;
	std::vector <size_t> positions;
	m_prefixFunction = GetSearchPrefixFunctions();
	while (x < text.size())
	{
		while ((y > -1) && (m_needle[y] != text[x]))
		{
			y = m_prefixFunction[y];
		}
		++x;
		++y;
		if (size_t(y) >= m_needle.size())
		{
			positions.push_back(x - size_t(y) + 1);
			y = m_prefixFunction[y];
		}
	}
	return positions;
}
