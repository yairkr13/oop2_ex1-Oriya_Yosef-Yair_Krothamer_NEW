#pragma once
#include "Function.h"
#include <memory>

class ComplexFunc : public Function
{
protected:
    std::shared_ptr<Function> function1;
    std::shared_ptr<Function> function2;
};