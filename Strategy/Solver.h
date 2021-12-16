#pragma once
#include "Functions.h"
#include "RootFindingAlgorithms.h"
#include <memory>
#include <utility>

template<typename ...Arguments>
class Solver final
{
private:
	std::unique_ptr<IRootFindingAlgorithm<Arguments...>> m_;
public:
	explicit Solver(std::unique_ptr<IRootFindingAlgorithm<Arguments...>> m);
	double operator()(const IFunc& f, Arguments...x, double epsilon) const;
};

template <typename ... Arguments>
inline Solver<Arguments...>::Solver(std::unique_ptr<IRootFindingAlgorithm<Arguments...>> m):m_(std::move(m)){}

template <typename ... Arguments>
inline double Solver<Arguments...>::operator()(const IFunc& f, Arguments... x, double epsilon) const
{
	return m_->operator()(f, x..., epsilon);
}


