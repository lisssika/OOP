#include "Solver.h"
#include  <memory>
#include <utility>

Solver::Solver(std::unique_ptr<IRootFindingAlgorithm> m) : m_(std::move(m))
{
} 

double Solver::operator()(const IFunc& f, const double x_left, const double x_right, const double epsilon) const
{
	return m_->operator()(f, x_left, x_right, epsilon);
}
