// 11.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "TriangleAndPoint.h"


int main()
{
	CTriangleAndPoint tap("input.txt");
	tap.WriteToOutputFile();
    return 0;
}

