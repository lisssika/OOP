#pragma once
#include "Functions.h"
#include "RootFindingAlgorithms.h"
#include <memory>

class Solver final
{
private:
	std::unique_ptr<IMethod> m_;
public:
	explicit Solver(std::unique_ptr<IMethod> m);
	double operator()(const IFunc& f, double x_left, double x_right, double epsilon) const;
};
