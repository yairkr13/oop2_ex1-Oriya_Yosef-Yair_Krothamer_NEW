#include "AddFunc.h"
#include "ComplexFunc.h"

AddFunc::AddFunc(const std::shared_ptr<Function>& ptr1,
    const std::shared_ptr<Function>& ptr2)
    : ComplexFunc(ptr1, ptr2, '+') 
{
}

double AddFunc::calculate(double x) const
{
	//call the calculate method of the two functions and
	//return their sum
    return (m_func1Ptr->calculate(x) + m_func2Ptr->calculate(x));
}
