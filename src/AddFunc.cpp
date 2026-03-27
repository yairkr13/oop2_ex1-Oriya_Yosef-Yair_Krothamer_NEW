#include "AddFunc.h"
#include <iostream>
#include <sstream>

void AddFunc::print(const std::string& x) const
{
    std::cout << "(";
    m_function1->print(x);
    std::cout << ") + (";
    m_function2->print(x);
    std::cout << ")";
}

double AddFunc::calculate(double x/*, bool toPrint*/) const
{
    double answer = m_function1->calculate(x) + m_function2->calculate(x);

    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << answer << "\n";
    return answer;
}