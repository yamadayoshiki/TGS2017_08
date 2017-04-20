#include "Enemy_CommonState_Shot.h"

//コンストラクタ
Enemy_CommonState_Shot::Enemy_CommonState_Shot(GSvector2& pos, GSmatrix4& mat)
	:Enemy_CommonState_AttackBase(pos, mat) {
}
// 各状態独自の初期化
void Enemy_CommonState_Shot::onUniqueInit(Actor & actor) {

}
// 更新処理
void Enemy_CommonState_Shot::onUpdate(Actor & actor, float deltaTime) {

}
// 衝突判定
void Enemy_CommonState_Shot::onCollide(const Actor & other) {

}
// 終了時の処理
void Enemy_CommonState_Shot::onEnd() {

}
// 入力処理
void Enemy_CommonState_Shot::onInput() {

}