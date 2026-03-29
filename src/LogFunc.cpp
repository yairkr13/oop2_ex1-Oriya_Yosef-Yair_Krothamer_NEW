#include "LogFunc.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>

LogFunc::LogFunc(int base):m_base(base) //takes a string or double
{ 
}

LogFunc* LogFunc::cloneImpl() const
{
	return new LogFunc(*this);
}

double LogFunc::calculate(double x) const//takes the value or save as m_xValue????
{
	return (std::log10(x) / std::log10(m_base));
}


void LogFunc::print(const std::string& x) const
{
	std::cout << "log"<< m_base <<"(" << x << ")"; //turn from number to string?????
}