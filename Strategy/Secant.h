#pragma once
#include "RootFindingAlgorithms.h"

class Secant final : public IRootFindingAlgorithm<double, double>
{
public:
	double operator()(const IFunc& f, double x1, double x2, double epsilon) const override;
};
