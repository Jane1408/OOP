#include "stdafx.h"
#include "FurSeal.h"

using namespace std;
typedef std::vector<std::vector<std::pair<int, int>>> Polygon;

CFurSeal::CFurSeal(std::string const& path)
{
	ReadDataFromFile(path);
	FindAnswer();
}


CFurSeal::~CFurSeal()
{
}

void CFurSeal::WriteIntotheFile()
{
	ofstream output("output.txt");
	output << m_answer.first << " " << m_answer.second << std::endl;

}

std::pair<unsigned, unsigned> CFurSeal::GetAnswer()
{
	return m_answer;
}

void CFurSeal::FindAnswer()
{
	FindPath();
	unsigned waterBlock = 0;
	int priceOfPath = m_polygon[m_width - 1][m_height - 1].second;
	while (priceOfPath - WATER_PLACE_PRICE >= 0)
	{
		++waterBlock;
		priceOfPath -= WATER_PLACE_PRICE;
	}
	m_answer.first = waterBlock;
	m_answer.second = priceOfPath;
}

void CFurSeal::ReadDataFromFile(std::string const & path)
{
	ifstream input(path);
	input >> m_height;
	input >> m_width;

	m_polygon.resize(m_height, vector<pair<int, int>>(m_width, {0, INT_MAX }));

	m_polygon[0][0].second = 1;
	string line;
	unsigned lineCount = 0;
	getline(input, line);
	while (getline(input, line))
	{
		unsigned symbolCount = 0;
		for (auto &symbol : line)
		{
			if (symbol == WATER_PLACE)
			{
				m_polygon[lineCount][symbolCount].first = WATER_PLACE_PRICE;
			}
			else
			{
				m_polygon[lineCount][symbolCount].first = SAND_PLACE_PRICE;
			}
			++symbolCount;
		}
		++lineCount;
	}
}

void CFurSeal::Wave(pair<int, int> const& pos, vector<pair<int, int>> & queue)
{
	if (pos.first > 0 && 
		m_polygon[pos.first - 1][pos.second].second >  m_polygon[pos.first][pos.second].second + m_polygon[pos.first - 1][pos.second].first)
	{
		m_polygon[pos.first - 1][pos.second].second = m_polygon[pos.first][pos.second].second + m_polygon[pos.first - 1][pos.second].first;
		queue.push_back({ pos.first - 1, pos.second });
	}
	if (pos.first < m_width - 1 &&
		m_polygon[pos.first + 1][pos.second].second >  m_polygon[pos.first][pos.second].second + m_polygon[pos.first + 1][pos.second].first)
	{
		m_polygon[pos.first + 1][pos.second].second = m_polygon[pos.first][pos.second].second + m_polygon[pos.first + 1][pos.second].first;
		queue.push_back({ pos.first + 1, pos.second });
	}
	if (pos.second > 0 &&
		m_polygon[pos.first][pos.second - 1].second >  m_polygon[pos.first][pos.second].second + m_polygon[pos.first][pos.second - 1].first)
	{
		m_polygon[pos.first][pos.second - 1].second = m_polygon[pos.first][pos.second].second + m_polygon[pos.first][pos.second - 1].first;
		queue.push_back({ pos.first, pos.second - 1 });
	}
	if (pos.second < m_height - 1 &&
		m_polygon[pos.first][pos.second + 1].second >  m_polygon[pos.first][pos.second].second + m_polygon[pos.first][pos.second + 1].first)
	{
		m_polygon[pos.first][pos.second + 1].second = m_polygon[pos.first][pos.second].second + m_polygon[pos.first][pos.second + 1].first;
		queue.push_back({ pos.first, pos.second + 1 });
	}
}

void CFurSeal::FindPath()
{
	std::vector<std::pair<int, int>> queue;
	queue.push_back({ 0, 0 });
	while (!queue.empty())
	{
		std::pair<int, int> pos = queue.back();
		queue.pop_back();
		Wave(pos, queue);
		
	}
}
