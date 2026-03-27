#include "AddFunc.h"
#include <iostream>
#include <sstream>
/*
//Need?
AddFunc::AddFunc(std::shared_ptr<Function> ptr1,
    std::shared_ptr<Function> ptr2)
    : ComplexFunc(ptr1, ptr2)
{
}*/
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
    //if (toPrint)
    //{
    std::ostringstream oss;
    oss << x;

    print(oss.str());
        //print(std::to_string(x));
    std::cout << " = " << answer << "\n";
    //}
    return answer;
}