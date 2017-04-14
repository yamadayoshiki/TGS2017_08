#include "PlayerStateMgr.h"

#include "PlayerState_Path.h"
#include "PlayerState_Enum.h"
#include "../PlayerMotionID.h"

// コンストラクタ
PlayerStateMgr::PlayerStateMgr(){}

// コンストラクタ
PlayerStateMgr::PlayerStateMgr(Vector3& pos, Matrix& mat){
	// ステートの追加
	add(PlayerState_Enum::N_IDLE, std::make_shared<PlayerState_N_Idle>(pos, mat));
	add(PlayerState_Enum::N_WALK, std::make_shared<PlayerState_N_Walk>(pos, mat));
	add(PlayerState_Enum::N_RUN, std::make_shared<PlayerState_N_Run>(pos, mat));
	add(PlayerState_Enum::N_JUMP, std::make_shared<PlayerState_N_Jump>(pos, mat));
	add(PlayerState_Enum::AWAKE, std::make_shared<PlayerState_Awake>(pos, mat));
	add(PlayerState_Enum::A_IDLE, std::make_shared<PlayerState_A_Idle>(pos, mat));
	add(PlayerState_Enum::A_WALK, std::make_shared<PlayerState_A_Walk>(pos, mat));
	add(PlayerState_Enum::A_RUN, std::make_shared<PlayerState_A_Run>(pos, mat));
	add(PlayerState_Enum::A_JUMP, std::make_shared<PlayerState_A_Jump>(pos, mat));
	add(PlayerState_Enum::A_QUICK, std::make_shared<PlayerState_A_Quick>(pos, mat));
	// 攻撃系ステート
	add(PlayerState_Enum::N_ATTACK1, std::make_shared<PlayerState_N_Attack>(pos, mat, PlayerMotionID::PUNCH_1, PlayerState_Enum::N_ATTACK2));
	add(PlayerState_Enum::N_ATTACK2, std::make_shared<PlayerState_N_Attack>(pos, mat, PlayerMotionID::PUNCH_2, PlayerState_Enum::N_ATTACK3));
	add(PlayerState_Enum::N_ATTACK3, std::make_shared<PlayerState_N_Attack>(pos, mat, PlayerMotionID::PUNCH_3, PlayerState_Enum::N_ATTACK3));
	add(PlayerState_Enum::A_ATTACK1, std::make_shared<PlayerState_A_Attack>(pos, mat, PlayerMotionID::KICK_1, PlayerState_Enum::A_ATTACK2));
	add(PlayerState_Enum::A_ATTACK2, std::make_shared<PlayerState_A_Attack>(pos, mat, PlayerMotionID::KICK_2, PlayerState_Enum::A_ATTACK3));
	add(PlayerState_Enum::A_ATTACK3, std::make_shared<PlayerState_A_Attack>(pos, mat, PlayerMotionID::KICK_3, PlayerState_Enum::A_ATTACK4));
	add(PlayerState_Enum::A_ATTACK4, std::make_shared<PlayerState_A_Attack>(pos, mat, PlayerMotionID::KICK_4, PlayerState_Enum::A_ATTACK4));
	//add(PlayerState_Enum::SPECIAL1, std::make_shared<PlayerState_N_Attack>(pos, mat, PlayerMotionID::PUNCH_1, PlayerState_Enum::N_ATTACK2));
	//add(PlayerState_Enum::SPECIAL2, std::make_shared<PlayerState_N_Attack>(pos, mat, PlayerMotionID::PUNCH_1, PlayerState_Enum::N_ATTACK2));
	add(PlayerState_Enum::ROLL, std::make_shared<PlayerState_N_Roll>(pos, mat));
	add(PlayerState_Enum::BIT, std::make_shared<PlayerState_N_Guard>(pos, mat));
	add(PlayerState_Enum::REACTION, std::make_shared<PlayerState_N_Guard>(pos, mat));
	add(PlayerState_Enum::NORMAL, std::make_shared<PlayerState_Normal>(pos, mat));
	add(PlayerState_Enum::DAMAGE, std::make_shared<PlayerState_N_Damage>(pos, mat));
	add(PlayerState_Enum::GUARD, std::make_shared<PlayerState_N_Guard>(pos, mat));
}


