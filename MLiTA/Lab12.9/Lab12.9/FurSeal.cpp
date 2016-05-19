#include "stdafx.h"
#include "FurSeal.h"

using namespace std;

// TODO: use structures instead of std::pair, comment what means each field in structure
typedef std::pair<int, int> PairInt;
typedef std::vector<std::vector<PairInt>> Polygon;

CFurSeal::CFurSeal(std::string const& path)
{
	ReadDataFromFile(path);
	FindAnswer();
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

	m_polygon.resize(m_height, vector<PairInt>(m_width, {0, INT_MAX }));

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
void FillQueue(Polygon & m_polygon, vector<PairInt> & queue, const PairInt & pos, int valX, int valY)
{
	if (m_polygon[pos.first + valX][pos.second + valY].second > m_polygon[pos.first][pos.second].second + m_polygon[pos.first + valX][pos.second + valY].first)
	{
		m_polygon[pos.first + valX][pos.second + valY].second = m_polygon[pos.first][pos.second].second + m_polygon[pos.first + valX][pos.second + valY].first;
		queue.push_back({ pos.first + valX, pos.second + valY });
	}
}
void CFurSeal::Wave(PairInt const& pos, vector<PairInt> & queue)
{
	if (pos.first > 0)
		FillQueue(m_polygon, queue, pos, -1, 0);
	if (pos.first < m_width - 1)
		FillQueue(m_polygon, queue, pos, 1, 0);
	if (pos.second > 0)
		FillQueue(m_polygon, queue, pos, 0, -1);
	if (pos.second < m_height - 1)
		FillQueue(m_polygon, queue, pos, 0, 1);
}

void CFurSeal::FindPath()
{
	std::vector<PairInt> queue = { {0, 0} };
	
	while (!queue.empty())
	{
		PairInt pos = queue.back();
		queue.pop_back();
		Wave(pos, queue);
	}
}
