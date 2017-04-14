#include "PlayerState_N_Attack.h"

#include "../../../../../../../Input/InputMgr.h"

// コンストラクタ
PlayerState_N_Attack::PlayerState_N_Attack(Vector3 & pos, Matrix & mat, PlayerMotionID motion, PlayerState_Enum next)
	: PlayerState_N_AttackBase(pos, mat), mMotion(motion), mNextState(next) {}

// 各状態独自の初期化
void PlayerState_N_Attack::onUniqueInit(Actor & actor){
	// モーションの遷移
	change_motion(actor, mMotion);

}

// 更新処理
void PlayerState_N_Attack::onUpdate(Actor & actor, float deltaTime){
	// 攻撃ボタンを押した場合
	if (InputMgr::GetInstance().IsButtonDown(Buttons::BUTTON_CIRCLE)) {
		// 攻撃時にだけ移動の入力を可能にすることで攻撃方向の決定
		move(actor, deltaTime, 0.0f);
		// 次の攻撃に移行
		change(mNextState);
	}
}
