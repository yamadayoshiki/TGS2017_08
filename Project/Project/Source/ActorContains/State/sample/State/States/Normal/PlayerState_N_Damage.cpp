#include "PlayerState_N_Damage.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../Base/ActorGroup.h"
#include "../../../../../../World/World.h"
#include "../../../../../../Scene/Base/SceneData.h"

// コンストラクタ
PlayerState_N_Damage::PlayerState_N_Damage(Vector3& pos, Matrix& mat) : PlayerState(pos, mat) {}

// 各状態独自の初期化
void PlayerState_N_Damage::unique_init(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::REACTION);
	// ダメージによるHPの減算
	actor.getWorld()->getSceneData()->getCurData().status.addDamage(5);
}

// 更新処理
void PlayerState_N_Damage::update(Actor & actor, float deltaTime){
	// アニメーションが終了したら待機状態に遷移
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::N_IDLE);
	}
}

// 衝突判定
void PlayerState_N_Damage::collide(const Actor & other) {}

// 終了時の処理
void PlayerState_N_Damage::end(){}

// 入力処理
void PlayerState_N_Damage::input(){}

