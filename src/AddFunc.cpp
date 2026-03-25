#include "AddFunc.h"
#include <iostream>

//Need?
AddFunc::AddFunc(std::shared_ptr<Function> ptr1,
    std::shared_ptr<Function> ptr2)
    : ComplexFunc(ptr1, ptr2)
{
}
void AddFunc::print(const std::string& x) const
{
    std::cout << "(";
    m_function1->print(x);
    std::cout << ") + (";
    m_function2->print(x);
}

void AddFunc::calculate(double x) const
{
    print(std::to_string(x));
    std::cout << ") =" <<
        m_function1->calculate(x) + m_function2->calculate(x) << "\n";

}