#pragma once
#include "Functions.h"
#include "Derivative.h"
#include  <memory>


class IMethod
{
public:
	virtual double operator()(const IFunc& f, double x_left, double x_right, double epsilon) const = 0;
	virtual ~IMethod() = default;
};

class Bisection final : public IMethod
{
public:
	double operator()(const IFunc& f, double x_left, double x_right, double epsilon) const override;
	~Bisection() override;
};

class Secant final : public IMethod
{
public:
	double operator()(const IFunc& f, double x1, double x2, double epsilon) const override;
	~Secant() override;
};

class Newton final : public IMethod
{
private:
	std::unique_ptr<IDerivative> derivative_;
public:
	Newton();
	double operator()(const IFunc& f, double x1, double x2, double epsilon) const override;
	~Newton() override;
};
