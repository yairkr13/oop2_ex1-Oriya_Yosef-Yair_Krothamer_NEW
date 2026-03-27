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
	double answer = std::log10(x) / std::log10(m_base);
	std::ostringstream oss;
	oss << x;

	print(oss.str());
	std::cout << " = " << answer << std::endl;
	return answer;
}

void LogFunc::print(const std::string& x) const
{
	std::cout << "log"<< m_base <<"(" << x << ")"; //turn from number to string?????
}