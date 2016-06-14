#include "stdafx.h"
#include "TriangleAndPoint.h"


CTriangleAndPoint::CTriangleAndPoint(std::string const & inputFile)
	:m_answer(false)
{
	ReadFromFile(inputFile);
	
}

CTriangleAndPoint::~CTriangleAndPoint()
{
}

bool CTriangleAndPoint::GetAnswer() const
{
	return m_answer;
}

void CTriangleAndPoint::WriteToOutputFile()
{
	std::ofstream output("output.txt");
	if (m_answer)
	{
		output << "In";
	}
	else
	{
		output << "Out";
	}
}

void CTriangleAndPoint::ReadFromFile(std::string const & inputFile)
{
	std::ifstream input(inputFile);
	Vertex vertex;
	for (size_t i = 0; i < 3; ++i)
	{
		input >> vertex.x;
		input >> vertex.y;
		m_triangle.push_back(vertex);
	}
	input >> m_point.x;
	input >> m_point.y;
	input.close();

	m_answer = IsInTriangle();
}

double GetValue(Vertex const& first, Vertex const& second, Vertex const& third)
{
	return (0.5 * abs((first.x - second.x) * (third.y - second.y) - (third.x - second.x) * (first.y - second.y)));
}

bool CTriangleAndPoint::IsInTriangle()
{
	if (((m_triangle[0].x == m_triangle[1].x) && (m_triangle[1].x == m_triangle[2].x))
		|| ((m_triangle[0].y == m_triangle[1].y) && (m_triangle[1].y == m_triangle[2].y)))
	{
		return false;
	}
	double sABC = GetValue(m_triangle[1], m_triangle[0], m_triangle[2]);
	double sABD = GetValue(m_triangle[1], m_triangle[0], m_point);
	double sDBC = GetValue(m_point, m_triangle[0], m_triangle[2]);
	double sADC = GetValue(m_triangle[1], m_point, m_triangle[2]);

	if (sABC == sABD + sDBC + sADC)
	{
		return true;
	}
	return false;
}
