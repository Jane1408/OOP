// main.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "KMP.h"


int main()
{
	CKMP kmp;
	kmp.DoAlgorithmKMP("input.txt");
	kmp.WriteIntoOutputFile();
    return 0;
}

