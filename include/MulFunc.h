#pragma once
#include "ComplexFunc.h"

class MulFunc : public ComplexFunc
{
public:
    //AddFunc()
    using ComplexFunc::ComplexFunc;
    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
};