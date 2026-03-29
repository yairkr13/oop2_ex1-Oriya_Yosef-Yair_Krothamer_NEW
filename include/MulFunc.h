#pragma once
#include "ComplexFunc.h"

class MulFunc : public ComplexFunc
{
public:
    MulFunc(const std::shared_ptr<Function>& ptr1,
        const std::shared_ptr<Function>& ptr2);
    double calculate(double x) const override;
};