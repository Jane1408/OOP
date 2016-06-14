#pragma once

struct Vertex
{
	int x = 0;
	int y = 0;
};

class CTriangleAndPoint
{
public:
	CTriangleAndPoint(std::string const & inputFile);
	~CTriangleAndPoint();

	bool GetAnswer() const;
	void WriteToOutputFile();

private:
	void ReadFromFile(std::string const& inputFile);
	bool IsInTriangle();
	std::vector<Vertex> m_triangle;
	Vertex m_point;
	bool m_answer;
};

