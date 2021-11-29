#pragma once
#include "Functions.h"
#include "Methods.h"

 
class Solver {
private:
	IMethod  * m;
public:
	Solver(IMethod* m_);
	double operator()(IFunc   const& f_, double x_left, double x_right, double epsilon);
};
