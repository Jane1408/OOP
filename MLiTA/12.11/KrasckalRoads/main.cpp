// KrasckalRoads.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KrasckalRoad.h"

int main()
{
	CKrasckalRoad road;
	road.SetLandMap("input1.txt");
	road.WriteIntoFile("output.txt");
    return 0;
}

