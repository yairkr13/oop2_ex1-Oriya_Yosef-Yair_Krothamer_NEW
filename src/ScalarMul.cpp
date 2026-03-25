#include <iostream>
#include "ScalarMul.h"

ScalarMul::ScalarMul(double scalar, std::shared_ptr<SimpleFunc> func) : 
	m_function(func)
{
	func->setFactor(scalar);
}

void ScalarMul::print(const std::string& x) const
{
	std::cout << m_factor << "*(";
	m_function->print(x);
	std::cout << ")";
}

double ScalarMul::calculate(double x) const
{
	double answer = m_factor * m_function->calculate(x);
	print(std::to_string(x));
	std::cout << " = " << answer << "\n";
	return answer;
}

ScalarMul* ScalarMul::cloneImpl() const
{
	return new ScalarMul(*this);
}