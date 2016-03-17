// Lab2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "VectorProcessor.h"

using namespace std;

int main()
{
	vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));
	ProcessVector(numbers);
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(cout, ", "));
    return 0;
}

