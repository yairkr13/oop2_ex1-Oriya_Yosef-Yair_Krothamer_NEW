#pragma once
#include "ComplexFunc.h"
//Oria pull
class AddFunc : public ComplexFunc
{
public:
    //AddFunc()
    //Yair
	using ComplexFunc::ComplexFunc;
    //AddFunc(std::shared_ptr<Function> ptr1, std::shared_ptr<Function> ptr2);
    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
};