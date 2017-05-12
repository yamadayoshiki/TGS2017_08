#include "MathSupport.h"
#include <gslib.h>


float MathSupport::GetAngle(const GSvector2& dynamic, const GSvector2& base) {
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
	result = result * 180.0f / 3.14f;

	//符号入れ替え
	if (cross < 0)
		result = -result;

	//結果を返す
	return result;
}

// ベクトルの回転
GSvector2 MathSupport::RotateVector(const GSvector2 & pos, const float & angle){
	// 回転後のベクトルを返す
	return GSvector2(pos.x * gsCos(angle) - pos.y * gsSin(angle), pos.x * gsSin(angle) + pos.y * gsCos(angle));
}
