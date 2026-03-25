#pragma once
#include "SimpleFunc.h"

class ScalarMul : public SimpleFunc
{
public:
	ScalarMul(double scalar, std::shared_ptr<SimpleFunc> func);
	//~ScalarMul : public SimpleFunc();
	void print(const std::string& x = "x") const override;
	void calculate(double x) const override;

protected:
	ScalarMul* cloneImpl() const override;
private:
	//Yair add
	double m_scalar;
	std::shared_ptr<SimpleFunc> m_function;
};
