#include "PolyFunc.h"
#include <iostream>

void PolyFunc::calculate(double x) const//takes the value or save as m_xValue????
{
	//--------------------
}

PolyFunc* PolyFunc::cloneImpl() const
{
	return new PolyFunc(*this);
}

void PolyFunc::print(const std::string& x) const
{
	for (int i = 0; i < m_numbers.size(); i++)
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