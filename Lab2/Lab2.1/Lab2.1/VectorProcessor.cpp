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
		double multiplier = maxElement;

		if (minElement != 0)
		{
			multiplier = maxElement / minElement;
		}
		transform(numbers, numbers.begin(), bind2nd(multiplies<double>(), multiplier));
		
	}
}
