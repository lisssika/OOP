#pragma once
#include "RootFindingAlgorithms.h"

class Bisection final : public IRootFindingAlgorithm<double, double>
{
public:
	double operator()(const IFunc& f, double x_left, double x_right, double epsilon) const override;
};
