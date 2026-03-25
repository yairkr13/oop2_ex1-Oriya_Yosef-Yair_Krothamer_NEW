#include "MulFunc.h"

void MulFunc::print(const std::string& x) const
{
	std::cout << "(";
	m_function1->print(x);
	std::cout << ") * (";
	m_function2->print(x);
}

void MulFunc::calculate(double x) const
{
	print(x);
	std::cout << ") ="<< 
		m_function1->calculate(x) * m_function2->calculate(x)<< "\n";

}