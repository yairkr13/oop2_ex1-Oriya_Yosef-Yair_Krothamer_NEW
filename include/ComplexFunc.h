#pragma once
#include "Function.h"
#include <memory>

class ComplexFunc : public Function
{
public:
    ComplexFunc(std::shared_ptr<Function> ptr1,
        std::shared_ptr<Function> ptr2);
protected:
    std::shared_ptr<Function> m_function1;
    std::shared_ptr<Function> m_function2;
};