#include "Derivative.h"
#include <stdexcept>
#include <limits>

double NumericalDerivative::operator()(IFunc const& f, double x, double delta) const {
	if (fabs(delta) < std::numeric_limits<double>::epsilon()) {
		throw std::runtime_error("Devision by 0. Delta must not be equal to 0");
	}
	return (f(x + delta) - f(x - delta)) / (2 * delta);
}

NumericalDerivative::~NumericalDerivative() = default;
