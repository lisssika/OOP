#include "Functions.h"
# define M_PI           3.14159265358979323846  /* pi */

double F0::operator()(double x) const {
	return x * x - 9;
}

F0::~F0() = default;

double SIN::operator()(double x) const {
	return sin(x);
}
SIN::~SIN() = default;
