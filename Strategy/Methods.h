#pragma once
#include "Functions.h"
#include "Derivative.h"


class IMethod {
public:
	virtual double operator()(IFunc   const& f_, double x_left, double x_right, double epsilon) const = 0;
	virtual ~IMethod() = default;
};

class Bisection final : public IMethod {
public:
	virtual double operator()(IFunc   const& f_, double x_left, double x_right, double epsilon) const override;
	virtual ~Bisection() override;
};

class Secant final : public IMethod {
public:
	virtual double operator()(IFunc   const& f, double x1, double x2, double epsilon) const override;
	virtual ~Secant() override;
};

class Newton final : public IMethod {
private:
	IDerivative* derivative;
public:
	Newton();
	virtual double operator()(IFunc   const& f, double x1, double x2, double epsilon)const override;
	virtual ~Newton() override;
};
