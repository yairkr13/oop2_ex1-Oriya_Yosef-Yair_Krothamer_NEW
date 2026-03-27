#pragma once
#include "Function.h"
#include <memory>

class ComplexFunc : public Function
{
public:
    ComplexFunc(const std::shared_ptr<Function>& ptr1,
        const std::shared_ptr<Function>& ptr2);
    
protected:
    std::shared_ptr<Function> m_func1Ptr;
    std::shared_ptr<Function> m_func2Ptr;//const??????????????
};