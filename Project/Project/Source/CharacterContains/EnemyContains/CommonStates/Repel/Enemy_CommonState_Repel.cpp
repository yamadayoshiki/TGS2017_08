#include "Enemy_CommonState_Repel.h"

//コンストラクタ
Enemy_CommonState_Repel::Enemy_CommonState_Repel(GSvector2& pos, GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}
// 各状態独自の初期化
void Enemy_CommonState_Repel::unique_init(Actor & actor) {
}
// 更新処理
void Enemy_CommonState_Repel::update(Actor & actor, float deltaTime) {
}
// 衝突判定
void Enemy_CommonState_Repel::collide(const Actor & other) {
}
// 終了時の処理
void Enemy_CommonState_Repel::end() {
}