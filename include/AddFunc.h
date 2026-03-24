#pragma once
#include "ComplexFunc.h"

class AddFunc : public ComplexFunc
{
public:
    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
};