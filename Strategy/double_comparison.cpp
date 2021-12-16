#include "double_comparison.h"
#include <cmath>

bool is_value_near_the_zero(double a, double epsilon)
{
	return fabs(a) < epsilon;
}
