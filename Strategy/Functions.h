#pragma once
#include <cmath>

class IFunc
{
public:
	virtual double operator()(double x) const = 0;
	virtual ~IFunc() = default;
};

class ParabolaWOffset final : public IFunc
{
public:
	double operator()(double x) const override;
	~ParabolaWOffset() override;
};

class Sin final : public IFunc
{
public:
	double operator()(double x) const override;
	~Sin() override;
};
