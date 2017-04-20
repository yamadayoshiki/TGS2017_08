#include "Enemy_CommonState_Rush.h"

// コンストラクタ
Enemy_CommonState_Rush::Enemy_CommonState_Rush(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_CommonState_AttackBase(pos, mat) {
}

// 各状態独自の初期化
void Enemy_CommonState_Rush::onUniqueInit(Actor & actor) {

}

// 更新処理
void Enemy_CommonState_Rush::onUpdate(Actor & actor, float deltaTime) {

}
// 衝突判定
void Enemy_CommonState_Rush::onCollide(const Actor & other) {

}
// 終了時の処理
void Enemy_CommonState_Rush::onEnd() {

}
// 入力処理
void Enemy_CommonState_Rush::onInput() {

}