#pragma once
#include "Functions.h"

class IDerivative
{
public:
	virtual double operator()(const IFunc& f, double x, double delta) const = 0;
	virtual ~IDerivative() = default;
};

class NumericalDerivative final : public IDerivative
{
public:
	double operator()(const IFunc& f, double x, double delta) const override;
	~NumericalDerivative() override;
};
