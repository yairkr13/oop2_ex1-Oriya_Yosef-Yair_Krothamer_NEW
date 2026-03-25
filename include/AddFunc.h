#pragma once
#include "ComplexFunc.h"

class AddFunc : public ComplexFunc
{
public:
    //AddFunc()
    //Yair
    AddFunc(std::shared_ptr<Function> ptr1, std::shared_ptr<Function> ptr2);
    void print(const std::string& x = "x") const override;
    void calculate(double x) const override;
};