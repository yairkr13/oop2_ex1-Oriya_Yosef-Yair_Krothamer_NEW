#include "SimpleFunc.h"
#include "ScalarMul.h"
//#include <memory>
std::shared_ptr<SimpleFunc> SimpleFunc::clone() const
{
	return std::shared_ptr<SimpleFunc>(cloneImpl());
}

//void SimpleFunc::setFactor(double scalar)
//{
//	m_factor *= scalar;
//}

std::shared_ptr<SimpleFunc> SimpleFunc::multiplyByScalar(double scalar) const 
{
    // יוצר עטיפה רגילה: למשל 5 * sin(x)
    // (בהנחה ש-clone מחזיר shared_ptr, אם לא - התאם את זה לקוד שלך)
    return std::make_shared<ScalarMul>(scalar, this->clone());
}