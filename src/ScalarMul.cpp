#include <iostream>
#include "ScalarMul.h"

ScalarMul::ScalarMul(double scalar,const std::shared_ptr<SimpleFunc>& func):
	m_factor(scalar),m_function(func)
{
}

std::shared_ptr<SimpleFunc> ScalarMul::multiplyByScalar(double scalar) const 
{
	//if the function we want to multiply is scalarMul - multiply the scalars
	return std::make_shared<ScalarMul>(m_factor * scalar, m_function->clone());
}

void ScalarMul::print(const std::string& x) const
{
	std::cout << m_factor << "*(";
	
	m_function->print(x);
	std::cout << ")";
}

double ScalarMul::calculate(double x) const
{
	return (m_factor * m_function->calculate(x));
}

ScalarMul* ScalarMul::cloneImpl() const
{
	return new ScalarMul(*this);
}
