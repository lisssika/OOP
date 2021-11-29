#include "pch.h"
#include "../Strategy/Solver.h"
#include <stdexcept>
#include <cmath>

TEST(Parabola, bisection) {
	Bisection* bisection_ = new(Bisection);
	Solver solver(bisection_);
	F0 f0;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(f0, -1, -10, epsilon), -3.f, epsilon * 10);
}

TEST(Parabola, secant) {
	Secant* secant = new(Secant);
	Solver solver(secant);
	F0 f0;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(f0, -1, -10, epsilon), -3.f, epsilon * 10);
}

TEST(Parabola, newton) {
	Newton* newton = new(Newton);
	Solver solver(newton);
	F0 f0;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(f0, -1, -10, epsilon), -3.f, epsilon * 10);
}

TEST(ThrowExcept, bisection) {
	Bisection* bisection_ = new(Bisection);
	Solver solver(bisection_);
	F0 f0;
	float epsilon = 1.e-5f;
	EXPECT_THROW(solver(f0, -4, -10, epsilon), std::runtime_error);
}

TEST(ThrowExcept, secant) {
	Secant* secant = new(Secant);
	Solver solver(secant);
	F0 f0;
	float epsilon = 1.e-5f;
	EXPECT_THROW(solver(f0, -4, -10, epsilon), std::runtime_error);
}

TEST(Sin_, bisection) {
	Bisection* bisection_ = new(Bisection);
	Solver solver(bisection_);
	SIN sin_;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(sin_, -3, 3, epsilon), 0.f, epsilon * 10);
}

TEST(Sin_, secant) {
	Secant* secant = new(Secant);
	Solver solver(secant);
	SIN sin_;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(sin_, -3, 3, epsilon), 0.f, epsilon * 10);
}

TEST(Sin_, newton) {
	Newton* newton = new(Newton);
	Solver solver(newton);
	SIN sin_;
	float epsilon = 1.e-5f;
	EXPECT_NEAR(solver(sin_, -1, 1, epsilon), 0.f, epsilon * 10);
}