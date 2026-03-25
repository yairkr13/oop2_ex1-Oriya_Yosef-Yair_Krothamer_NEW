#include "SimpleFunc.h"

std::shared_ptr<SimpleFunc> SimpleFunc::clone() const
{
	return std::shared_ptr<SimpleFunc>(cloneImpl());
}

void SimpleFunc::setFactor(double scalar)
{
	m_factor *= scalar;
}