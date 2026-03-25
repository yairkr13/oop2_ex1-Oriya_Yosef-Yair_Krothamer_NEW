#pragma once
#include <vector>
#include "SimpleFunc.h"
#include <string>

class PolyFunc : public SimpleFunc
{
public:
    //PolyFunc(const std::vector<double>& numbers);
    PolyFunc(const std::string& line);
    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;

protected:
    PolyFunc* cloneImpl() const override;

private:
    std::vector<double> m_numbers;
};