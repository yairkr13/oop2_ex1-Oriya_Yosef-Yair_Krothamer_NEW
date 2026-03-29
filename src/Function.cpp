#include "Function.h"
#include <iostream>
#include <sstream>

void Function::printRes(double x) const
{
    double answer = calculate(x);

    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << std::round(answer * 100) / 100 << "\n";
}