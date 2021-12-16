#include <stdexcept>
#include "double_comparison.h"
#include "Secant.h"

double Secant::operator()(const IFunc& f, double x1, double x2, double epsilon) const
{
	double f_x1 = f(x1);
	double f_x2 = f(x2);
	if (f_x1 * f_x2 > 0) {
		throw  std::runtime_error("the function must intersect the x axis on the given segment");
	}
	while (!is_value_near_the_zero(x1 - x2, epsilon))
	{
		f_x1 = f(x1);
		f_x2 = f(x2);
		if (is_value_near_the_zero(f_x1, epsilon))
		{
			return x1;
		}
		if (is_value_near_the_zero(f_x2, epsilon))
		{
			return x2;
		}
		if (is_value_near_the_zero(f_x2 - f_x1, epsilon))
		{
			throw std::runtime_error("The values of the function are equal, division by 0.");
		}
		const double x3 = x1 - (x2 - x1) * f_x1 / (f_x2 - f_x1);
		x1 = x2;
		x2 = x3;
	}
	return x2;
}