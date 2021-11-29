#include "pch.h"
#include "../Strategy/Solver.h"
#include <stdexcept>
#include <memory>
#include <utility>

TEST(Parabola, bisection)
{
	std::unique_ptr<IMethod> bisection = std::make_unique<Bisection>();
	const Solver solver(std::move(bisection));
	const ParabolaWOffset parabola_w_offset;
	double epsilon = 1.e-5;
	EXPECT_NEAR(solver(parabola_w_offset, -1, -10, epsilon), -3., epsilon * 10);
}

TEST(Parabola, secant)
{
	std::unique_ptr<IMethod>secant = std::make_unique<Secant>();
	const Solver solver(std::move(secant));
	const ParabolaWOffset parabola_w_offset;
	const double epsilon = 1.e-5;
	EXPECT_NEAR(solver(parabola_w_offset, -1, -10, epsilon), -3., epsilon * 10);
}

TEST(Parabola, newton)
{
	std::unique_ptr<IMethod> newton = std::make_unique<Newton>();
	const Solver solver(std::move(newton));
	const ParabolaWOffset parabola_w_offset;
	const double epsilon = 1.e-5;
	EXPECT_NEAR(solver(parabola_w_offset, -1, -10, epsilon), -3., epsilon * 10);
}

TEST(ThrowExcept, bisection)
{
	std::unique_ptr<IMethod> bisection = std::make_unique<Bisection>();
	const Solver solver(std::move(bisection));
	const ParabolaWOffset parabola_w_offset;
	double epsilon = 1.e-5;
	EXPECT_THROW(solver(parabola_w_offset, -4, -10, epsilon), std::runtime_error);
}

TEST(ThrowExcept, secant)
{
	std::unique_ptr<IMethod>secant = std::make_unique<Secant>();
	const Solver solver(std::move(secant));
	const ParabolaWOffset parabola_w_offset;
	const double epsilon = 1.e-5;
	EXPECT_THROW(solver(parabola_w_offset, -4, -10, epsilon), std::runtime_error);
}

TEST(Sin_, bisection)
{
	std::unique_ptr<IMethod> bisection = std::make_unique<Bisection>();
	const Solver solver(std::move(bisection));
	const Sin sin_;
	double epsilon = 1.e-5;
	EXPECT_NEAR(solver(sin_, -3, 3, epsilon), 0.f, epsilon * 10);
}

TEST(Sin_, secant)
{
	std::unique_ptr<IMethod>secant = std::make_unique<Secant>();
	const Solver solver(std::move(secant));
	const Sin sin_;
	const double epsilon = 1.e-5;
	EXPECT_NEAR(solver(sin_, -3, 3, epsilon), 0.f, epsilon * 10);
}

TEST(Sin_, newton)
{
	std::unique_ptr<IMethod> newton = std::make_unique<Newton>();
	const Solver solver(std::move(newton));
	const Sin sin_;
	const double epsilon = 1.e-5;
	EXPECT_NEAR(solver(sin_, -1, 1, epsilon), 0.f, epsilon * 10);
}
