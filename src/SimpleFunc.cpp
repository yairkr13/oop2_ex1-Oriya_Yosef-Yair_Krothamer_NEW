#include "SimpleFunc.h"
#include "ScalarMul.h"

std::shared_ptr<SimpleFunc> SimpleFunc::clone() const
{
	return std::shared_ptr<SimpleFunc>(cloneImpl());
}

std::shared_ptr<SimpleFunc> SimpleFunc::multiplyByScalar(double scalar) const 
{
    //create the scalarMul from start
    return std::make_shared<ScalarMul>(scalar, this->clone());
}