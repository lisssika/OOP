#include "Functions.h"

double ParabolaWOffset::operator()(double x) const
{
	return x * x - 9;
}

ParabolaWOffset::~ParabolaWOffset() = default;

double Sin::operator()(double x) const
{
	return sin(x);
}

Sin::~Sin() = default;
