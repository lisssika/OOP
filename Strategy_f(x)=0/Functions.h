#pragma once
#include <cmath>

class IFunc {
public:
	virtual double operator()(double x) const = 0;
	virtual ~IFunc() = default;
};

class F0 final : public IFunc {
public:
	virtual double operator()(double x) const override;
	virtual ~F0();
};

class SIN final : public IFunc {
public:
	virtual double operator()(double x) const override;
	virtual ~SIN();
};
