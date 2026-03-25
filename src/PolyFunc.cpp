#include "PolyFunc.h"
#include <iostream>

double PolyFunc::calculate(double x) const//takes the value or save as m_xValue????
{
	double answer = 0;
	double xVal = 1;
	for (size_t i = 0;i < m_numbers.size(); i++)
	{
		answer += m_numbers[i] * (xVal);
		xVal *= x; 
	}
	print(std::to_string(x));
	std::cout << " = " << answer << std::endl;
	return answer;
}

PolyFunc* PolyFunc::cloneImpl() const
{
	return new PolyFunc(*this);
}

void PolyFunc::print(const std::string& x) const
{
	for (size_t i = 0; i < m_numbers.size(); i++)
	{
		if (m_numbers[i] == 0)
			continue;
		if (i != 0 && m_numbers[i] > 0)
			std::cout << " + ";
		else if (i != 0)
			std::cout << " - ";
		std::cout << m_numbers[i] << "*(" << x << ")^" << i; //handle minus
	}
}