#pragma once
#include "SimpleFunc.h"

class ScalarMul : public SimpleFunc
{
public:
	ScalarMul(double scalar,const std::shared_ptr<SimpleFunc>& func);
	void print(const std::string& x = "x") const override;
	double calculate(double x) const override;
	std::shared_ptr<SimpleFunc> multiplyByScalar(double scalar) const override;
protected:
private:
	ScalarMul* cloneImpl() const override;
	std::shared_ptr<SimpleFunc> m_function;
	double m_factor = 1.0;
};
