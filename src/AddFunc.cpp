#include "AddFunc.h"
#include <iostream>

void AddFunc::print(const std::string& x) const
{
	std::cout << "(";
	m_function1->print(x);
	std::cout << ") + (";
	m_function2->print(x);
}

void AddFunc::calculate(double x) const
{
	print(std::tostring(x));
	std::cout << ") =" <<
		m_function1->calculate(x) + m_function2->calculate(x) << "\n";

}