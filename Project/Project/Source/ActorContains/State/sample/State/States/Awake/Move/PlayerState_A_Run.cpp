#include "PlayerState_A_Run.h"

#include "../../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_A_Run::PlayerState_A_Run(Vector3& pos, Matrix& mat) : PlayerState_A_MoveBase(pos, mat) {}

// 各状態独自の初期化
void PlayerState_A_Run::onUniqueInit(Actor & actor) {
	// モーションの変更
	change_motion(actor, PlayerMotionID::AWAKE_RUN);
}

// 各状態独自の初期化
void PlayerState_A_Run::onUpdate(Actor & actor, float deltaTime) {
	// 移動処理
	move(actor, deltaTime, 2.0f);
}

