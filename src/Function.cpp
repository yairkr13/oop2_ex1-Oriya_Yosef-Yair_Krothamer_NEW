#include "Function.h"
#include <iostream>
#include <sstream>

//this function call the function's calculate method and print the result 
// in the format "f(x) = answer", where f(x) is the function's string
// representation and answer is the calculated value rounded to 2 decimal places
void Function::printRes(double x) const
{
    double answer = calculate(x);

    std::ostringstream oss;
    oss << x;

    print(oss.str());
    std::cout << " = " << std::round(answer * 100) / 100 << "\n";
}