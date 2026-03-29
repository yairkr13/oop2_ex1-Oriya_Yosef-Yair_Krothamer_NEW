#pragma once
#include "SimpleFunc.h"

class LogFunc : public SimpleFunc
{
public:
    LogFunc(int base = 10);

    void print(const std::string& x = "x") const override;
    //double calculate(double x) const override;
    double calculate(double x) const override;
    //void printRes(double x) const;
protected:
    LogFunc* cloneImpl() const override;
    

private:
    double m_base;
};