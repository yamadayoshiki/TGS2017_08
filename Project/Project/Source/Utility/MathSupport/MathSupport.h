#ifndef MATHSUPPORT_H_
#define MATHSUPPORT_H_

#include <gslib.h>

namespace MathSupport
{
	//二つのベクトルの角度を求める(-180<value<=180)
	float GetAngle(const GSvector2& dynamic, const GSvector2& base = GSvector2(0.0f, -1.0f));
}

#endif