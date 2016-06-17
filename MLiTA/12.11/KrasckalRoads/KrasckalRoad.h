#pragma once
class CKrasckalRoad
{
public:
	CKrasckalRoad();
	~CKrasckalRoad();
	void SetLandMap(std::string const& fileName);
	int GetPrice();
	std::multimap<int, int> GetAsphaltRoads();
	void WriteIntoFile(std::string const& fileName);
private:
	void ReadFromFile(std::string const& fileName);
	void DoKrasckal();
	void AddAsphaltRoad(int firstTown, int secondTown);
	bool CheckLoop(int first, int second) const;
	void AddNewSet(int first, int second);

	std::multimap<int, int> m_asphaltRoads;
	std::multimap<int, std::pair<int, int>> m_edges;
	std::vector<std::set<int>> m_usedVertex;
	int m_towersCount = 0;
	int m_price = 0;
};

