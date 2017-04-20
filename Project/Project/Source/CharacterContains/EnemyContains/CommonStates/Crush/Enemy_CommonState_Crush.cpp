#include "Enemy_CommonState_Crush.h"

//コンストラクタ
Enemy_CommonState_Crush::Enemy_CommonState_Crush(
	GSvector2& pos,
	GSmatrix4& mat)
	:Enemy_BaseState(pos, mat) {
}

// 各状態独自の初期化
void Enemy_CommonState_Crush::unique_init(Actor & actor) {
}

// 更新処理
void Enemy_CommonState_Crush::update(Actor & actor, float deltaTime) {
}

// 衝突判定
void Enemy_CommonState_Crush::collide(const Actor & other) {
}

// 終了時の処理
void Enemy_CommonState_Crush::end() {
}