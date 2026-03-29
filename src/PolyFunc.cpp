#include "PolyFunc.h"
#include <iostream>
#include <sstream>
#include <cmath>

PolyFunc::PolyFunc(const std::string& line)
{
	int n;
	std::istringstream iss(line);
	iss >> n;
	m_coefficients.resize(n);
	for (int i = 0; i < n; i++)
		iss >> m_coefficients[i];
}

double PolyFunc::calculate(double x) const
{
	double answer = 0;
	double xVal = 1;
	for (size_t i = 0;i < m_coefficients.size(); i++)
	{
		answer += m_coefficients[i] * (xVal);
		xVal *= x; 
	}
	return answer;
}

PolyFunc* PolyFunc::cloneImpl() const
{
	return new PolyFunc(*this);
}

void PolyFunc::print(const std::string& x) const
{
	bool allZero = true;
	bool isSigned = true;

	for (int i = static_cast<int>(m_coefficients.size())-1; i >= 0; i--)
	{
		if (m_coefficients[i] == 0)
			continue;
		if (!isSigned && m_coefficients[i] != 0) //dont print "+" or "-" before the first number
		{
			if (m_coefficients[i] > 0)
				std::cout << " + ";
			else if (m_coefficients[i] < 0)
				std::cout << " - ";

		}
		else if (m_coefficients[i] < 0)
			std::cout << "-";


		allZero = false;
		isSigned = false;
		std::cout << std::abs(m_coefficients[i]) << "*(" << x << ")^" << i;
	}
	if (allZero) // all the vector with zeroes
		std::cout << 0;
}
