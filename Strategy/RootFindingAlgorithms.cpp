#include "RootFindingAlgorithms.h"
#include <stdexcept>
#include "Functions.h"
#include "Derivative.h"

bool is_value_near_the_zero(double a, double epsilon)
{
	return fabs(a) < epsilon;
}

double Bisection::operator()(const IFunc& f, double x_left, double x_right, double epsilon) const
{
	double f_left = f(x_left);
	double f_right = f(x_right);
	if (f_left*f_right > 0)
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

Bisection::~Bisection() = default;

double Secant::operator()(const IFunc& f, double x1, double x2, double epsilon) const
{
	double f_x1 = f(x1);
	double f_x2 = f(x2);
	if (f_x1 * f_x2 > 0) {
		throw  std::runtime_error("the function must intersect the x axis on the given segment");
	}
	while (!is_value_near_the_zero(x1-x2, epsilon))
	{
		f_x1 = f(x1);
		f_x2 = f(x2);
		if (is_value_near_the_zero(f_x1, epsilon))
		{
			return x1;
		}
		if(is_value_near_the_zero(f_x2,epsilon))
		{
			return x2;
		}
		if (is_value_near_the_zero(f_x2 - f_x1, epsilon))
		{
			throw std::runtime_error("The values of the function are equal, division by 0.");
		}
		double x3 = x1 - (x2 - x1) * f_x1 / (f_x2 - f_x1);
		x1 = x2;
		x2 = x3;
	}
	return x2;
}

Secant::~Secant() = default;

Newton::Newton(std::unique_ptr<IDerivative> derivative)
{
	derivative_ = std::move(derivative);
}

double Newton::operator()(const IFunc& f, double x1, double x2, double epsilon) const
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
Newton::~Newton() = default;

