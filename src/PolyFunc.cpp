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
	//print(std::to_string(x));
	std::cout << " = " << answer << std::endl;
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
	
	for (size_t i = 0; i < m_numbers.size(); i++)
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
	if(allZero) // all the vector with zeroes
		std::cout << 0;
}

//void PolyFunc::print(const std::string& x) const
//{
//	bool firstTerm = true;
//
//	for (size_t i = 0; i < m_numbers.size(); i++)
//	{
//		if (m_numbers[i] == 0)
//			continue;
//
//		if (!firstTerm)
//		{
//			if (m_numbers[i] > 0)
//				std::cout << " + ";
//			else
//				std::cout << " - ";
//		}
//		else
//		{
//			if (m_numbers[i] < 0)
//				std::cout << "-";
//		}
//
//		std::cout << std::abs(m_numbers[i]) << "*(" << x << ")^" << i;
//		firstTerm = false;
//	}
//
//	if (firstTerm)
//		std::cout << "0";
//}