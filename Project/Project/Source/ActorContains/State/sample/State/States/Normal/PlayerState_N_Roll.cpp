#include "PlayerState_N_Roll.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"

// コンストラクタ
PlayerState_N_Roll::PlayerState_N_Roll(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// 各状態独自の初期化
void PlayerState_N_Roll::unique_init(Actor & actor){
	// モーションの変更
	change_motion(actor, PlayerMotionID::ROLL, 2.0f);
}

// 更新処理
void PlayerState_N_Roll::update(Actor & actor, float deltaTime){
	// 前方に移動
	mPosition += mRotation.Backward() * 2.0f;
	
	// アニメーションが終了したら待機状態に遷移
	if (actor.getAnim().isAnimEnd()) {
		change(PlayerState_Enum::A_IDLE);
	}
}

// 衝突判定
void PlayerState_N_Roll::collide(const Actor & other) {}

// 終了時の処理
void PlayerState_N_Roll::end(){}

// 入力処理
void PlayerState_N_Roll::input(){
	// 覚醒状態に切り替え
	if (awake_pad()) change(PlayerState_Enum::N_IDLE);
}

