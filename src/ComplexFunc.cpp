#include "ComplexFunc.h"
#include <iostream>

ComplexFunc::ComplexFunc(const std::shared_ptr<Function>& ptr1,
	const std::shared_ptr<Function>& ptr2, char op): m_func1Ptr(ptr1),
	m_func2Ptr(ptr2), m_operator(op)//get 2 pointers to Function and the operator
{
}

void ComplexFunc::print(const std::string& x) const
{
	//use the m_operator to print the correct operator
    // between the two functions, and call the print method of each 
    // function to print them in the correct format
    std::cout << "(";
    m_func1Ptr->print(x);
    std::cout << ") " << m_operator << " (";
    m_func2Ptr->print(x);
    std::cout << ")";
}