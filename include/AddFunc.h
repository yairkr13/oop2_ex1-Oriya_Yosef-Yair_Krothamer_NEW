#pragma once
#include "ComplexFunc.h"
//Oria pull
class AddFunc : public ComplexFunc
{
public:
    //AddFunc()
    //Yair
    AddFunc(const std::shared_ptr<Function>& ptr1,
        const std::shared_ptr<Function>& ptr2);
	//using ComplexFunc::ComplexFunc;
    //AddFunc(std::shared_ptr<Function> ptr1, std::shared_ptr<Function> ptr2);
    //void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
};