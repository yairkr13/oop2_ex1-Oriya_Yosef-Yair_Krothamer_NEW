#pragma once
#include "SimpleFunc.h"

class LogFunc : public SimpleFunc
{
public:
    LogFunc(int base = 10);

    void print(const std::string& x = "x") const override;
    void calculate(double x) const override;

protected:
    LogFunc* cloneImpl() const override;

private:
    double m_base;
};