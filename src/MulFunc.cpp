#include "MulFunc.h"
#include "ComplexFunc.h"

MulFunc::MulFunc(const std::shared_ptr<Function>& ptr1,
    const std::shared_ptr<Function>& ptr2)
    : ComplexFunc(ptr1, ptr2, '*')
{
}

double MulFunc::calculate(double x) const
{
	return (m_func1Ptr->calculate(x) * m_func2Ptr->calculate(x));
}