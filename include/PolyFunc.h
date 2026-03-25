#pragma once
#include <vector>
#include "SimpleFunc.h"

class PolyFunc : public SimpleFunc
{
public:
    //PolyFunc(const std::vector<double>& numbers);

    void print(const std::string& x = "x") const override;
    void calculate(double x) const override;

protected:
    PolyFunc* cloneImpl() const overrid e;

private:
    std::vector<double> m_numbers;
};