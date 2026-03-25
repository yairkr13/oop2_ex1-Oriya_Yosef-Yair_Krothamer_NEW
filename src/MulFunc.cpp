#include "MulFunc.h"
#include <iostream>

void MulFunc::print(const std::string& x) const
{
    std::cout << "(";
    m_function1->print(x);
    std::cout << ") * (";
    m_function2->print(x);
    std::cout << ")";
}

double MulFunc::calculate(double x) const
{
	double answer = m_function1->calculate(x) * m_function2->calculate(x);
    print(std::to_string(x));
    std::cout << " = " << answer << "\n";
	return answer;

}