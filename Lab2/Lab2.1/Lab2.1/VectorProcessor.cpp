#include "stdafx.h"
#include <boost/range/algorithm/transform.hpp>
#include "VectorProcessor.h"

using namespace std;
using boost::transform;

void ProcessVector(vector<double> & numbers)
{
	if (!numbers.empty())
	{
		double minElement = *min_element(numbers.begin(), numbers.end());
		double maxElement = *max_element(numbers.begin(), numbers.end());
		 
		double multiply = maxElement / minElement;

		auto MyltiplicationNumber = [multiply](double number)
		{
			return number =  number * multiply;
		};
		transform(numbers, numbers.begin(), MyltiplicationNumber);
		sort(numbers.begin(), numbers.end());
	}
}
