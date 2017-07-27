#include "MathSupport.h"
#include <gslib.h>
#include "../../Define/Def_Nakayama.h"
#include "../../Define/Def_Float.h"
#include <cmath>

// 二つのベクトルの角度を求める(-180<value<=180)
float MathSupport::GetVec2ToVec2Angle(const GSvector2& dynamic, const GSvector2& base) {
	//結果
	float result = 0;

	//正規化
	GSvector2 base_N = base.getNormalized();
	GSvector2 dynamic_N = dynamic.getNormalized();

	//外積を求める
	float cross = base_N.CCW(dynamic_N);

	//内積を求める
	float dot = base_N.dot(dynamic_N);

	//内積から角度へ変換
	result = acosf(dot);
	result = result * 180.0f / PI;

	//符号入れ替え
	if (cross < 0)
		result = -result;

	//結果を返す
	return result;
}

float MathSupport::DegreeToRadian(float degree) {
	return degree / 180.0f * PI;
}

// ベクトルの回転
GSvector2 MathSupport::RotateVector(const GSvector2 vector, const float radian) {
	// 回転後のベクトルを返す
	float xcos = vector.x * gsCos(radian);
	float ysin = vector.y * gsSin(radian);
	float xsin = vector.x * gsSin(radian);
	float ycos = vector.y * gsCos(radian);
	float x = xcos - ysin;
	float y = xsin + ycos;
	return GSvector2(x, y);
}


// 度数法をGSvector2に変換
GSvector2 MathSupport::GetAngleToVector2(const float& angle)
{
	//変換
	float x = cosf(angle * PI / 180);
	float y = sinf(angle * PI / 180);

	//結果を返す
	return GSvector2(x, y);
}

//角度の正規化(-180<value<=180)
float MathSupport::GetAngleClamp(const float angle) {
	float result = angle;
	if (result >= 180.0f)
		result = 180.0f;

	else if (-180.0f >= result)
		result = -180.0f;

	if (-180.0f == result)
		result = 180.0f;

	return result;
}

//角度の正規化(-180<=value<=180)
float MathSupport::GetAngleNormalize(const float angle) {
	float result = angle;
	while (result < -180)
	{
		result += 360;
	}
	while (180 < result)
	{
		result -= 360;
	}
	return result;
}

//自然数の桁数を求める
unsigned MathSupport::GetDigit(unsigned num) {
	unsigned result = log10(num) + 1;
	if (result == 0)
		result = 1;
	return result;
}

//自然数を切り取る
unsigned int MathSupport::GetCutNum(const unsigned int value, const unsigned int head, const unsigned int length) {
	//桁の数
	int digit = GetDigit(value);

	if (digit < length)
		return 0;

	//切り捨てる桁の長さ
	int high = head - 1;
	int low = digit - (high + length);

	//結果変数
	int result = 0;
	//上位桁切り捨て
	result = value % (int)std::pow(10, low + length);
	//下位桁切り捨て
	result = result / (int)std::pow(10, low);

	return result;
}

//角度を軸平行角度に変換(-90,0,90,180)
float MathSupport::AngleCnvAAAngle(const float angle) {
	float result = GetAngleNormalize(angle);
	if (result <= -135 || 135 <= result)
		result = 180;
	else if (result <= -45)
		result = -90;
	else if (result <= 45)
		result = 0;
	else if (result <= 135)
		result = 90;

	return result;
}

