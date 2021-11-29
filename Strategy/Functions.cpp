#include "Functions.h"

double F0::operator()(double x) const {
	return x * x - 9;
}

F0::~F0() = default;

double SIN::operator()(double x) const {
	return sin(x);
}
SIN::~SIN() = default;
