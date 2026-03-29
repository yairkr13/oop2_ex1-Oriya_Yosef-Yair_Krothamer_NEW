#pragma once
#include "ComplexFunc.h"

class AddFunc : public ComplexFunc
{
public:
    AddFunc(const std::shared_ptr<Function>& ptr1,
        const std::shared_ptr<Function>& ptr2);
    double calculate(double x) const override;
};