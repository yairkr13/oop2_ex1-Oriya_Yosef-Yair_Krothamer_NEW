#include "LogFunc.h"
#include <cmath>
#include <iostream>
#include <iomanip>

LogFunc::LogFunc(int base):m_base(base) //takes a string or double
{ 
	// זה לא טוב, צריך להעביר מהקונטרולר
	// Controller -> קורא קלט מהמשתמש
	// LogFunc -> מקבל ערכים מוכנים ועושה חישוב בלבד
	//std::cin >> m_base;
}

LogFunc* LogFunc::cloneImpl() const
{
	return new LogFunc(*this);
}

void LogFunc::calculate(double x) const//takes the value or save as m_xValue????
{
	double answer = std::log10(x) / std::log10(m_base);
	print(std::to_string(x));
	std::cout << " = " << answer << std::endl;
}

void LogFunc::print(const std::string& x) const
{
	std::cout << "log"<< m_base <<"(" << x << ")"; //turn from number to string?????
}