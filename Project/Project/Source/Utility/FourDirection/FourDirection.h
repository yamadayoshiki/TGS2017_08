#ifndef FORDIRECTION_H_
#define FORDIRECTION_H_
#include "../TurnDirection/TurnDirection.h"
#include <iostream>
#include <unordered_map>

struct GSvector2;

/*
４方向列挙
size_t(unsigned int)に代入するため
ebum classではなくenum/0以上で定義
*/
enum FourDirectionName
{
	Up = 0,		//上
	Right,		//右
	Down,		//下
	Left,		//左

	None,		//なし
};

//４方向
struct FourDirection
{
	struct
	{
		FourDirectionName name;
	};

	//コンストラクタ
	explicit FourDirection(const FourDirectionName directionName);
	//コンストラクタ
	explicit FourDirection(const GSvector2& vector);
	//コンストラクタ
	explicit FourDirection(const float angle);
	//デフォルトコンストラクタ
	FourDirection();
	//指定方向に回転(90度)
	FourDirection Turn(TurnDirection turnDirection);
	//指定方向に回転(90度)
	FourDirection GetTurn(TurnDirection turnDirection) const;
	//反転
	FourDirection TurnOver();
	//反転
	FourDirection GetTurnOver() const;
	//GSvector2に置き換え
	GSvector2 GetVector2() const;
	//角度に置き換え
	float GetAngle() const;
	//Gsvector2をFourDirectionNameに変換
	static FourDirection GetVector2ToFourDirection(const GSvector2& vector);

	//比較演算子
	bool operator==(const FourDirection& fourDirection) const;
	bool operator!=(const FourDirection& fourDirection) const;
};

//比較演算子
inline bool FourDirection::operator==(const FourDirection& fourDirection) const {
	const FourDirection& me = *this;
	return me.name == fourDirection.name;
}

//比較演算子
inline bool FourDirection::operator!=(const FourDirection& fourDirection) const {
	return !(this->operator==(fourDirection));
}

//ハッシュ関数の特殊化
template<>
struct std::hash<FourDirection> {
	size_t operator()(const FourDirection& key) const
	{
		size_t hash;
		hash = key.name;
		return hash;
	}
};

#endif // !FORDIRECTION_H_