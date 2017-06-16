#include "MathSupport.h"
#include <gslib.h>
#include "../../Define/Def_Nakayama.h"
#include "../PathFinder/Point2.h"
#include "../../Define/Def_Float.h"

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

// ベクトルの回転
GSvector2 MathSupport::RotateVector(const GSvector2 & pos, const float & angle) {
	float f_angle = GetAngleNomalize(angle);

	// 回転後のベクトルを返す
	return GSvector2(pos.x * gsCos(f_angle) - pos.y * gsSin(f_angle), pos.x * gsSin(f_angle) + pos.y * gsCos(f_angle));
}


// 度数法をGSvector2に変換
GSvector2 MathSupport::GetAngleToVector2(const float& angle)
{
	//変換
	float x = gsCos(angle * PI / 180);
	float y = gsSin(angle * PI / 180);

	//結果を返す
	return GSvector2(x, y);
}


// 座標をマスに変換
Point2 MathSupport::GetVector2ToPoint2(const GSvector2 vector)
{
	//結果変数
	Point2 result;

	//マスに合わせる
	int x = vector.x / CHIP_SIZE + 1;
	int y = vector.y / CHIP_SIZE + 1;

	result.x = x;
	result.y = y;

	return result;
}

//角度の正規化(-180<value<=180)
float MathSupport::GetAngleNomalize(const float angle) {
	float result = angle;
	if (result >= 180.0f)
		result = 180.0f;

	else if (-180.0f >= result)
		result = -180.0f;

	if (-180.0f == result)
		result = 180.0f;

	return result;
}

//自然数の桁数を求める
unsigned MathSupport::GetDigit(unsigned num) {
	return log10(num) + 1;
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

