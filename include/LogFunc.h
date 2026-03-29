#pragma once
#include "SimpleFunc.h"

class LogFunc : public SimpleFunc
{
public:
    LogFunc(double base = 10);

    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
protected:
    LogFunc* cloneImpl() const override;//private?????????????????
private:
    double m_base;
};