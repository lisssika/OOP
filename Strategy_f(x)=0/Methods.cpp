#include "Methods.h"
#include <stdexcept>
#include "Functions.h"
#include <float.h>
#include <limits>
double Bisection::operator()(IFunc const& f_, double x_left, double x_right, double epsilon) const {

	if (f_(x_left) * f_(x_right) > 0) {
		throw std::runtime_error("the function must intersect the x axis on the given segment");
	}
	while (fabs(x_right - x_left) > epsilon) {
		if (fabs(f_(x_left)) < epsilon) {
			return x_left;
		}
		if (fabs(f_(x_right)) < epsilon) {
			return x_right;
		}
		auto x_middle = (x_right + x_left) / 2;
		if (f_(x_middle) * f_(x_right) < 0) {
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

double Secant::operator()(IFunc   const& f, double x1, double x2, double epsilon) const {
	if (f(x1) * f(x2) > 0) {
		throw  std::runtime_error("the function must intersect the x axis on the given segment");
	}
	while (fabs(x1 - x2) > epsilon)
	{
		if (fabs(f(x1)) < epsilon) {
			return x1;
		}
		if (fabs(f(x2)) < epsilon) {
			return x2;
		}
		if (fabs(f(x2) - f(x1))< DBL_EPSILON) { // сравнение double
			throw std::runtime_error("The values of the function are equal, division by 0.");
		}
		else {
			auto x3 = x1 - ((x2 - x1) * f(x1)) / (f(x2) - f(x1));
			x1 = x2;
			x2 = x3;
		}
	}
	return x1;
}
Secant:: ~Secant() = default;

Newton::Newton() {
	derivative = new(NumericalDerivative);
}
double Newton::operator()(IFunc   const& f, double x1, double x2, double epsilon)const {
	double x = x1;
	while (fabs(f(x)) > epsilon) {
		double derivative_value = derivative->operator()(f, x, 1.e-5);
		if (fabs(derivative_value)< std::numeric_limits<double>::epsilon()) {
			throw std::runtime_error("Devision by 0. Function must be strictly monotone.");
		}
		x = x - f(x) / derivative_value;
	}
	return x;
}
Newton:: ~Newton() {
	delete(derivative);
}
