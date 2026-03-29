#include "LogFunc.h"
#include <cmath>
#include <iostream>
#include <iomanip>

LogFunc::LogFunc(double base):m_base(base) 
{ 
}

LogFunc* LogFunc::cloneImpl() const
{
	return new LogFunc(*this);
}

double LogFunc::calculate(double x) const
{
	return (std::log10(x) / std::log10(m_base));
}

void LogFunc::print(const std::string& x) const
{
	std::cout << "log"<< m_base <<"(" << x << ")"; 
}