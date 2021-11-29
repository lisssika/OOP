#include "Solver.h"
#include  <memory>
#include <utility>

Solver::Solver(std::unique_ptr <IMethod>& m) :m_(std::move(m)) {} // я понимаю, что move когда передаём нужен. Но не понимаю, нужен ли он тут.

double Solver::operator()(IFunc const& f, const double x_left, const double x_right, const double epsilon) const {
	return m_->operator()(f, x_left, x_right, epsilon);
}
