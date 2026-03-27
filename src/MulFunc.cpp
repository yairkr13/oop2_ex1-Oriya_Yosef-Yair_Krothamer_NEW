#include "MulFunc.h"
#include <iostream>
#include <sstream>

void MulFunc::print(const std::string& x) const
{
    std::cout << "(";
    m_func1Ptr->print(x);
    std::cout << ") * (";
    m_func2Ptr->print(x);
    std::cout << ")";
}

double MulFunc::calculate(double x) const
{
	double answer = m_func1Ptr->calculate(x) * m_func2Ptr->calculate(x);
    //print(std::to_string(x));
    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << std::round(answer * 100) / 100 << "\n";
	return answer;

}