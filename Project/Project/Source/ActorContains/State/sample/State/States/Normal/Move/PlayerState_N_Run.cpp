#include "PlayerState_N_Run.h"

#include "../../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_N_Run::PlayerState_N_Run(Vector3& pos, Matrix& mat) : PlayerState_N_MoveBase(pos, mat) {}

// 各状態独自の初期化
void PlayerState_N_Run::onUniqueInit(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::NORMAL_RUN);
}

// 各状態独自の初期化
void PlayerState_N_Run::onUpdate(Actor & actor, float deltaTime){
	// 移動処理
	move(actor, deltaTime, 1.5f);
}


