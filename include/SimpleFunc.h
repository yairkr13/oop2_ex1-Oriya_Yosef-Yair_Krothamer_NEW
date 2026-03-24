#pragma once
#include "Function.h"
#include <memory>

class SimpleFunc: public Function
{
public:
	//SimpleFunc: public Function();
	//~SimpleFunc: public Function();
	std::shared_ptr<SimpleFunc> clone() const; // הבנתי שעדיף...
	//std::shared_ptr<SimpleFunc> clone();

protected:
	virtual SimpleFunc* cloneImpl() const = 0;

};

