#pragma once
#include "Functions.h"
#include "Derivative.h"
#include  <memory>

template<typename ... Arguments>
class IRootFindingAlgorithm
{
public:
	virtual double operator()(const IFunc& f, Arguments ... x, double epsilon) const = 0;
	virtual ~IRootFindingAlgorithm() = default;
};

class Bisection final : public IRootFindingAlgorithm<double, double>
{
public:
	double operator()(const IFunc& f, double x_left, double x_right, double epsilon) const override;
	~Bisection() override;
};

class Secant final : public IRootFindingAlgorithm<double, double>
{
public:
	double operator()(const IFunc& f, double x1, double x2, double epsilon) const override;
	~Secant() override;
};

class Newton final : public IRootFindingAlgorithm<double>
{
private:
	std::unique_ptr<IDerivative> derivative_;
public:
	explicit Newton(std::unique_ptr<IDerivative> derivative);
	double operator()(const IFunc& f, double x1, double epsilon) const override;
	~Newton() override;
};
