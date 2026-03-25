#include "ComplexFunc.h"

ComplexFunc::ComplexFunc(std::shared_ptr<Function> ptr1,
	std::shared_ptr<Function> ptr2): m_function1(ptr1),
	m_function2(ptr2)//get 2 pointers to Function
{
}