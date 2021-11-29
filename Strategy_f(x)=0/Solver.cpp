#include "Solver.h"

Solver::Solver(IMethod* m_) :m(m_) {}

double Solver::operator()(IFunc const& f_, double x_left, double x_right, double epsilon) {
	return m->operator()(f_, x_left, x_right, epsilon);
}
