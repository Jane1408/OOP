// main.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "KMP.h"


int main()
{
	CKMP kmp;
	kmp.AlgorithmKMP("input.txt");
	kmp.WriteIntoOutputFile();
    return 0;
}

