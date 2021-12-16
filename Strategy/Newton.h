#pragma once
#include <memory>
#include "Derivative.h"
#include "RootFindingAlgorithms.h"

class Newton final : public IRootFindingAlgorithm<double>
{
private:
	std::unique_ptr<IDerivative> derivative_;
public:
	explicit Newton(std::unique_ptr<IDerivative> derivative);
	double operator()(const IFunc& f, double x1, double epsilon) const override;
};

