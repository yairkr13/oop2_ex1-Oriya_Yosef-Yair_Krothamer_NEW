#pragma once
#include "ComplexFunc.h"

class MulFunc : public ComplexFunc
{
public:
    //AddFunc()
    MulFunc(const std::shared_ptr<Function>& ptr1,
        const std::shared_ptr<Function>& ptr2);
    //using ComplexFunc::ComplexFunc;
   // void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
};