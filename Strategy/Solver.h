#pragma once
#include "Functions.h"
#include "Methods.h"
#include <memory>

 
class Solver final{
private:
	std::unique_ptr<IMethod> m_;
public:
	explicit Solver(std::unique_ptr < IMethod>& m);
	double operator()(IFunc   const& f, double x_left, double x_right, double epsilon) const;
};
