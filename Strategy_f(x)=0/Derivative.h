#pragma once
#include "Functions.h"

class IDerivative {
public:
	virtual double operator()(IFunc   const& f, double x, double delta) const = 0;
	virtual ~IDerivative() = default;
};

class NumericalDerivative final : public IDerivative {
public:
	virtual double operator()(IFunc   const& f, double x, double delta)const override;
	virtual ~NumericalDerivative();
};
