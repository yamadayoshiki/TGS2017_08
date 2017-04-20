#include "Enemy_CommonState_RushPreliminary.h"

//コンストラクタ
Enemy_CommonState_RushPreliminary::Enemy_CommonState_RushPreliminary(
	GSvector2& pos, 
	GSmatrix4& mat)
	:Enemy_CommonState_AttackBase(pos,mat){
}

// 各状態独自の初期化
void Enemy_CommonState_RushPreliminary::onUniqueInit(Actor & actor) {}
void Enemy_CommonState_RushPreliminary::onUpdate(Actor & actor, float deltaTime)
{
}
// 更新処理
void onUpdate(Actor & actor, float deltaTime) {}
// 衝突判定
void Enemy_CommonState_RushPreliminary::onCollide(const Actor & other) {}
// 終了時の処理
void Enemy_CommonState_RushPreliminary::onEnd() {}
// 入力処理
void Enemy_CommonState_RushPreliminary::onInput() {}