#include "ComplexFunc.h"

ComplexFunc::ComplexFunc(const std::shared_ptr<Function>& ptr1,
	const std::shared_ptr<Function>& ptr2): m_func1Ptr(ptr1),
	m_func2Ptr(ptr2)//get 2 pointers to Function
{
}