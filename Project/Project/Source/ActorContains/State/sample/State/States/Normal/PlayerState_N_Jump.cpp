#include "PlayerState_N_Jump.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Define.h"

#include <algorithm>

// コンストラクタ
PlayerState_N_Jump::PlayerState_N_Jump(Vector3& pos, Matrix& mat) : PlayerState(pos, mat),mJumpPower(0) {}

// 各状態独自の初期化
void PlayerState_N_Jump::unique_init(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::NORMAL_JUMP);
	// ジャンプ力の初期化
	mJumpPower = PLAYER_JUMP_POWER;
}

// 更新処理
void PlayerState_N_Jump::update(Actor & actor, float deltaTime){
	// ジャンプ力の減算
	mJumpPower = std::max<float>(mJumpPower - PLAYER_JUMP_DUMP, 0.0f);
	// 座標にジャンプ力を加算
	mPosition += Vector3::Down * GRAVITY + Vector3::Up * mJumpPower;
	// 移動の入力処理
	move(actor, deltaTime, 2.5f);
	// 床に設置したまたはかつジャンプ力がなくなった場合に待機状態に遷移
	if (actor.isOnFloor() && mJumpPower == 0) {
		change(PlayerState_Enum::N_IDLE);
	}
}

// 衝突判定
void PlayerState_N_Jump::collide(const Actor & other) {
	// 攻撃されたらダメージ状態に遷移
	if (other.getName() == "Enemy_AttackRange") {
		change(PlayerState_Enum::DAMAGE);
	}
}

// 終了時の処理
void PlayerState_N_Jump::end(){}

// 入力処理
void PlayerState_N_Jump::input(){}





