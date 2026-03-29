#include "AddFunc.h"
#include <iostream>
#include <sstream>
#include "ComplexFunc.h"

AddFunc::AddFunc(const std::shared_ptr<Function>& ptr1,
    const std::shared_ptr<Function>& ptr2)
    : ComplexFunc(ptr1, ptr2, '+') // <--- מוסרים לאב את הסימן הנכון!
{
    // גוף הבנאי נשאר ריק
}
/*
void AddFunc::print(const std::string& x) const
{
    std::cout << "(";
    m_func1Ptr->print(x);
    std::cout << ") + (";
    m_func2Ptr->print(x);
    std::cout << ")";
}*/

double AddFunc::calculate(double x/*, bool toPrint*/) const
{
    double answer = m_func1Ptr->calculate(x) + m_func2Ptr->calculate(x);

    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << std::round(answer * 100) / 100 << "\n";
    return answer;
}