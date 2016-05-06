#pragma once

typedef std::vector<std::vector<std::pair<int, int>>> Polygon;

static const char WATER_PLACE = '@';
static const char SAND_PLACE = '.';

static const int WATER_PLACE_PRICE = 2501;
static const int SAND_PLACE_PRICE = 1;


class CFurSeal
{
public:
	CFurSeal(std::string const& path);
	~CFurSeal();

	void WriteIntotheFile();
	std::pair<unsigned, unsigned> GetAnswer();
private:
	void ReadDataFromFile(std::string const& path);
	void FindAnswer();
	void Wave(std::pair<int, int> const& pos, std::vector<std::pair<int, int>> & queue);

	void FindPath();
	Polygon m_polygon;
	int m_width;
	int m_height;

	std::pair<unsigned, unsigned> m_answer;
};

