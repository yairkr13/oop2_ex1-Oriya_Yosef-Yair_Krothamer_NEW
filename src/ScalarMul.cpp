#include <iostream>
#include "ScalarMul.h"
#include <sstream>
/*
ScalarMul::ScalarMul(double scalar, std::shared_ptr<SimpleFunc> func) : 
	m_function(func)
{
	func->setFactor(scalar);
}*/


ScalarMul::ScalarMul(double scalar, std::shared_ptr<SimpleFunc> func)
{
	m_factor = scalar;
	//m_function = func ? func->clone() : nullptr;
	m_function = func;//ask chet!!!!!!!!!!!!!!!!!!!!!!!!
}

std::shared_ptr<SimpleFunc> ScalarMul::multiplyByScalar(double scalar) const {
	// במקום ליצור עטיפה כפולה, אנחנו פשוט מכפילים את הסקלרים!
	// אם היה לנו 2 ועכשיו קיבלנו 5, הסקלר החדש יהיה 10.
	// הפונקציה הפנימית נשארת אותה פונקציה בדיוק.

	return std::make_shared<ScalarMul>(m_factor * scalar, m_function->clone());
}

void ScalarMul::print(const std::string& x) const
{
	
	std::cout << m_factor << "*(";
	
	m_function->print(x);
	std::cout << ")";
	
	/*
	if (m_factor != 1.0)
	{
		std::cout << m_factor << "*(";
		m_function->print(x);
		std::cout << ")";
	}*/
}

double ScalarMul::calculate(double x) const
{
	double answer = m_factor * m_function->calculate(x);
	std::ostringstream oss;
	oss << x;

	print(oss.str());
	std::cout << " = " << answer << "\n";
	return answer;
}

ScalarMul* ScalarMul::cloneImpl() const
{
	return new ScalarMul(*this);
}
