// main.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BonnieAndClyde.h"


int main()
{
	CBonnieAndClyde bac("input.txt");
	bac.WriteInOutputFile();
    return 0;
}

