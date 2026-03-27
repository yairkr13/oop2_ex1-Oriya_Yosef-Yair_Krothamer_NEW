#include "MulFunc.h"
#include <iostream>
#include <sstream>

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
    //print(std::to_string(x));
    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << answer << "\n";
	return answer;

}