#include "PlayerState_Normal.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_Normal::PlayerState_Normal(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// 各状態独自の初期化
void PlayerState_Normal::unique_init(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::INJURED);
}

// 更新処理
void PlayerState_Normal::update(Actor & actor, float deltaTime){
	// アニメーションが終了したら待機状態に遷移
	if (actor.getAnim().isAnimEnd()) change(PlayerState_Enum::N_IDLE);
}

// 衝突判定
void PlayerState_Normal::collide(const Actor & other) {}

// 終了時の処理
void PlayerState_Normal::end(){}

// 入力処理
void PlayerState_Normal::input(){}


