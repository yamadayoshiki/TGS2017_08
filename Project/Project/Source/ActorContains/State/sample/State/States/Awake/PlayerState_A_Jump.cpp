#include "PlayerState_A_Jump.h"

#include "../../../../../../Define.h"
#include "../../../../../../Scene/Base/SceneData.h"
#include "../../../../../../World/World.h"
#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

#include <algorithm>

// コンストラクタ
PlayerState_A_Jump::PlayerState_A_Jump(Vector3& pos, Matrix& mat) : PlayerState(pos, mat), mJumpPower(0) {}

// 各状態固有の初期化
void PlayerState_A_Jump::unique_init(Actor & actor) {
	// モーションの変更
	change_motion(actor, PlayerMotionID::AWAKE_JUMP);
	// ジャンプ力の初期化
	mJumpPower = PLAYER_JUMP_POWER;
}

// 更新処理
void PlayerState_A_Jump::update(Actor & actor, float deltaTime) {
	// ジャンプ力の減算
	mJumpPower = std::max<float>(mJumpPower - PLAYER_JUMP_DUMP, 0.0f);
	// 座標にジャンプ力を加算
	mPosition += Vector3::Down * GRAVITY + Vector3::Up * mJumpPower;
	// 移動の入力処理
	move(actor, deltaTime, 2.5f);
	// 床に設置したまたはかつジャンプ力がなくなった場合に待機状態に遷移
	if (actor.isOnFloor() && mJumpPower == 0) {
		change(PlayerState_Enum::A_IDLE);
	}

	// 徐々に体力を減らしていく
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(PLAYER_AWAKE_BLOOD_USE);
	if (actor.getWorld()->getSceneData()->getCurData().status.mParams.hp <= 20) {
		change(PlayerState_Enum::NORMAL);
	}
}

// 衝突判定
void PlayerState_A_Jump::collide(const Actor & other){
	// 攻撃されたらダメージ状態に遷移
	if (other.getName() == "Enemy_AttackRange") {
		change(PlayerState_Enum::DAMAGE);
	}
}

// 終了時の処理
void PlayerState_A_Jump::end() {}

// 入力処理
void PlayerState_A_Jump::input() {}




