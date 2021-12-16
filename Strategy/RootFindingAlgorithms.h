#pragma once
#include "Functions.h"
template<typename ... Arguments>
class IRootFindingAlgorithm
{
public:
	virtual double operator()(const IFunc& f, Arguments ... x, double epsilon) const = 0;
	virtual ~IRootFindingAlgorithm() = default;
};