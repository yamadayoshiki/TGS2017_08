#ifndef MATHSUPPORT_H_
#define MATHSUPPORT_H_

#include <gslib.h>

namespace MathSupport
{
	// 円周率
	static const float PI = 3.141592f;

	// 二つのベクトルの角度を求める(-180<value<=180)
	float GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base = GSvector2(1.0f, 0.0f));

	// ベクトルの回転
	GSvector2 RotateVector(const GSvector2 vector, const float angle);

	// 度数法をGSvector2に変換
	GSvector2 GetAngleToVector2(const float& angle);

	//角度の正規化(-180<value<=180)
	float GetAngleClamp(const float angle);

	//角度の正規化(-180<=value<=180)
	float GetAngleNormalize(const float angle);

	//自然数の桁数を求める
	unsigned int GetDigit(const unsigned num);

	//自然数を切り取る
	unsigned int GetCutNum(const unsigned int value, const unsigned int head, const unsigned int length);

	//角度を軸平行角度に変換(-90,0,90,180)
	float AngleCnvAAAngle(const float angle);
}

#endif