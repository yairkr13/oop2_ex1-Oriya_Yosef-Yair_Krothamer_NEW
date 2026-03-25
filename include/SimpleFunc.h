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
	void setFactor(double scalar);
protected:
	virtual SimpleFunc* cloneImpl() const = 0;
	double m_factor=1.0;

};

