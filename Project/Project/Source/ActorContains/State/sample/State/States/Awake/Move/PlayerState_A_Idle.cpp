#include "PlayerState_A_Idle.h"

#include "../../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_A_Idle::PlayerState_A_Idle(Vector3& pos, Matrix& mat) : PlayerState_A_MoveBase(pos, mat) {}

// 各状態固有の初期化
void PlayerState_A_Idle::onUniqueInit(Actor & actor) {
	// モーションの変更
	change_motion(actor, PlayerMotionID::AWAKE_IDLE);
}








