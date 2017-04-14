#include "PlayerState_A_Walk.h"

#include "../../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_A_Walk::PlayerState_A_Walk(Vector3 & pos, Matrix & mat) : PlayerState_A_MoveBase(pos, mat) {}

// 各状態独自の初期化
void PlayerState_A_Walk::onUniqueInit(Actor & actor) {
	// モーションの変更
	change_motion(actor, PlayerMotionID::AWAKE_WALK);
}

// 各状態独自の初期化
void PlayerState_A_Walk::onUpdate(Actor & actor, float deltaTime) {
	// 移動処理
	move(actor, deltaTime, 1.0f);
}
