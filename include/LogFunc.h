#pragma once
#include "SimpleFunc.h"

class LogFunc : public SimpleFunc
{
public:
    LogFunc(double base = 10);

    void print(const std::string& x = "x") const override;
    double calculate(double x) const override;
protected:
private:
    LogFunc* cloneImpl() const override;
    double m_base;
};