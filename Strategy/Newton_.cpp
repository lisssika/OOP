#include <stdexcept>
#include "double_comparison.h"
#include "Newton.h"
Newton::Newton(std::unique_ptr<IDerivative> derivative)
{
	derivative_ = std::move(derivative);
}

double Newton::operator()(const IFunc& f, double x1, double epsilon) const
{
	double x = x1;
	double f_x = f(x);
	while (!is_value_near_the_zero(f_x, epsilon))
	{
		const double derivative_value = derivative_->operator()(f, x, 1.e-5);
		if (is_value_near_the_zero(derivative_value, epsilon))
		{
			throw std::runtime_error("Division by 0. Function must be strictly monotone.");
		}
		x = x - f_x / derivative_value;
		f_x = f(x);
	}
	return x;
}