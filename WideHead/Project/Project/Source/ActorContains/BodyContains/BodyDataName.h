#ifndef BODYDATANAME_H_
#define BODYDATANAME_H_
namespace Body {
	//衝突図形データ構造
	enum class BodyDataName {
		None,		//なし
		AABB_32,	//一辺32の正方形
		AABB_64,	//一辺64の正方形

		PlayerAttackRange,	//プレイヤー攻撃範囲
		Player_Open,				//プレイヤーがアームを開いている
		Player_Close,				//プレイヤーがアームを閉じている
		Player_Clip,				//プレイヤーが敵を挟んでいる
	};
}
#endif // !BODYDATANAME_H_
