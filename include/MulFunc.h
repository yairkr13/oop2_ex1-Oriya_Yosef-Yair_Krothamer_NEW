#pragma once
#include "ComplexFunc.h"

class AddFunc : public ComplexFunc
{
public:
    //AddFunc()
    void print(const std::string& x = "x") const override;
    void calculate(double x) const override;
};