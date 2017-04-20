#include "Enemy_CommonState_Thrown.h"

//コンストラクタ
Enemy_CommonState_Thrown::Enemy_CommonState_Thrown(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}
// 各状態独自の初期化
void Enemy_CommonState_Thrown::unique_init(Actor & actor) {
}
// 更新処理
void Enemy_CommonState_Thrown::update(Actor & actor, float deltaTime) {
}
// 衝突判定
void Enemy_CommonState_Thrown::collide(const Actor & other) {}
// 終了時の処理
void Enemy_CommonState_Thrown::end() {
}