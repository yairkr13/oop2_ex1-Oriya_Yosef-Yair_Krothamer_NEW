#pragma once
#include <string>

class Function
{
public:
	//אבל המחלקה היא מחלקת בסיס פולימורפית (יש בה פונקציות וירטואל) ל
	// לכן הסדקטרטור חייב להיות וירטואל....
	virtual ~Function() = default;
	virtual void print(const std::string& x="x") const = 0;
	//virtual double calculate(double x) const = 0;//change to operator ()
	virtual double calculate(double x) const = 0;//change to operator ()
	virtual void printRes(double x) const;
protected:
	//double m_xValue;
	//virtual double calculate(double x) const = 0;//change to operator ()
private:

};
