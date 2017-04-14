#include "PlayerState_N_Guard.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Input/InputMgr.h"

// コンストラクタ
PlayerState_N_Guard::PlayerState_N_Guard(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat){}

// 各状態独自の初期化
void PlayerState_N_Guard::unique_init(Actor & actor){
	// モーションの変更
	//change_motion(actor, PlayerMotionID::);
}

// 更新処理
void PlayerState_N_Guard::update(Actor & actor, float deltaTime) {
	// アニメーションが終了したら待機状態に遷移
	if (actor.getAnim().isAnimEnd()) change(PlayerState_Enum::N_IDLE);
}


// 衝突判定
void PlayerState_N_Guard::collide(const Actor & other) {
	if (other.getName() == "Enemy_AttackRange") {
		//change(PlayerState_Enum::);
	}
}

// 終了時の処理
void PlayerState_N_Guard::end(){}

// 入力処理
void PlayerState_N_Guard::input(){
	// 覚醒状態に切り替え
	if (awake_pad()) change(PlayerState_Enum::AWAKE);
	// ガード解除
	else if (!InputMgr::GetInstance().IsButtonOn(Buttons::BUTTON_L1)) change(PlayerState_Enum::N_IDLE);
}

