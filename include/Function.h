#pragma once
#include <string>

class Function
{
public:
	virtual ~Function() = default;
	virtual void print(const std::string& x="x") const = 0;
	virtual double calculate(double x) const = 0;//change to operator ()
	virtual void printRes(double x) const;
protected:
private:

};
