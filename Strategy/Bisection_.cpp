#include <stdexcept>
#include "Bisection.h"
#include "double_comparison.h"

double Bisection::operator()(const IFunc& f, double x_left, double x_right, double epsilon) const
{
	double f_left = f(x_left);
	double f_right = f(x_right);
	if (f_left * f_right > 0)
	{
		throw std::runtime_error("the function must intersect the x axis on the given segment");
	}
	while (!is_value_near_the_zero(x_right - x_left, epsilon))
	{
		f_left = f(x_left);
		f_right = f(x_right);

		if (is_value_near_the_zero(f_left, epsilon))
		{
			return x_left;
		}
		if (is_value_near_the_zero(f_right, epsilon))
		{
			return x_right;
		}
		const auto x_middle = (x_right + x_left) / 2;
		if (f(x_middle) * f(x_right) < 0)
		{
			x_left = x_middle;
		}
		else
		{
			x_right = x_middle;
		}
	}
	return x_left;
}
