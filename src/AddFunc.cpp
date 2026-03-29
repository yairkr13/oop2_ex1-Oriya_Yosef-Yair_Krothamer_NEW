#include "AddFunc.h"
#include "ComplexFunc.h"

AddFunc::AddFunc(const std::shared_ptr<Function>& ptr1,
    const std::shared_ptr<Function>& ptr2)
    : ComplexFunc(ptr1, ptr2, '+') 
{
}

double AddFunc::calculate(double x) const
{
    return (m_func1Ptr->calculate(x) + m_func2Ptr->calculate(x));
}
