#pragma once
#include <vector>
#include "SimpleFunc.h"
#include <string>

class PolyFunc : public SimpleFunc
{
public:
    PolyFunc(const std::string& line);
    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;

protected:

private:
    PolyFunc* cloneImpl() const override;
    std::vector<double> m_coefficients;
};