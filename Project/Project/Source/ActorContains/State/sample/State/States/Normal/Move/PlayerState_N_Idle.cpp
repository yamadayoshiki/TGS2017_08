#include "PlayerState_N_Idle.h"

#include "../../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_N_Idle::PlayerState_N_Idle(Vector3& pos, Matrix& mat) : PlayerState_N_MoveBase(pos, mat){}

// 各状態固有の初期化
void PlayerState_N_Idle::onUniqueInit(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::NORMAL_IDLE);
}









