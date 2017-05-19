#ifndef MATHSUPPORT_H_
#define MATHSUPPORT_H_

#include <gslib.h>

class Point2;

namespace MathSupport
{
	// 円周率
	static const float PI = 3.141592f;

	// 二つのベクトルの角度を求める(-180<value<=180)
	float GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base = GSvector2(0.0f, -1.0f));

	// ベクトルの回転
	GSvector2 RotateVector(const GSvector2 & pos, const float & angle);

	// 度数法をGSvector2に変換
	GSvector2 GetAngleToVector2(const float& angle);

	// 座標をマスに変換
	Point2 GetVector2ToPoint2(const GSvector2 vector);

	//角度の正規化(-180<value<=180)
	float GetAngleNomalize(const float angle);
}

#endif