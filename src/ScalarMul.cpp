#include "ScalarMul.h"

ScalarMul::ScalarMul(double scalar, std::shared_ptr<SimpleFunc> func) : 
	m_scalar(scalar), m_function(func)
{ }

void ScalarMul::print(const std::string& x) const
{
	std::cout << m_scalar << "*(";
	m_function->print(x);
	std::count << ")";
}

void ScalarMul::calculate(double x) const
{
	print(x);
	std::cout << " = " << m_scalar * m_function->calculate(x) << "\n";
}