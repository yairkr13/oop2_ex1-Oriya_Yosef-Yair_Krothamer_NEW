#include "PolyFunc.h"
#include <iostream>
#include <sstream>
#include <cmath>

PolyFunc::PolyFunc(const std::string& line)
{
	int n;
	std::istringstream iss(line);
	iss >> n;
	m_numbers.resize(n);
	for (int i = 0; i < n; i++)
		iss >> m_numbers[i];
}

double PolyFunc::calculate(double x) const//takes the value or save as m_xValue????
{
	double answer = 0;
	double xVal = 1;
	for (size_t i = 0;i < m_numbers.size(); i++)
	{
		answer += m_numbers[i] * (xVal);
		xVal *= x; 
	}
	std::ostringstream oss;
	oss << x;

	print(oss.str());
	std::cout << " = " << std::round(answer * 100) / 100 << std::endl;
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

	for (int i = m_numbers.size()-1; i >= 0; i--)
	{
		if (m_numbers[i] == 0)
			continue;
		if (!isSigned && m_numbers[i] != 0) //dont print "+" or "-" before the first number
		{
			if (m_numbers[i] > 0)
				std::cout << " + ";
			else if (m_numbers[i] < 0)
				std::cout << " - ";

		}
		else if (m_numbers[i] < 0)
			std::cout << "-";


		allZero = false;
		isSigned = false;
		std::cout << std::abs(m_numbers[i]) << "*(" << x << ")^" << i;
	}
	if (allZero) // all the vector with zeroes
		std::cout << 0;
}
