#pragma once
#include "Function.h"
#include <memory>

class SimpleFunc: public Function
{
public:
	std::shared_ptr<SimpleFunc> clone() const; 
	virtual std::shared_ptr<SimpleFunc> multiplyByScalar(double scalar) const;
protected:
	virtual SimpleFunc* cloneImpl() const = 0;
};

