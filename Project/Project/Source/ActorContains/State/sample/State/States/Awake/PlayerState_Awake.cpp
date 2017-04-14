#include "PlayerState_Awake.h"

#include "../../PlayerState_Enum.h"
#include "../../../PlayerMotionID.h"
#include "../../../../../../Define.h"

// コンストラクタ
PlayerState_Awake::PlayerState_Awake(Vector3 & pos, Matrix & mat) : PlayerState(pos, mat) {}

// 各状態固有の初期化
void PlayerState_Awake::unique_init(Actor & actor){
	// モーションの変更(覚醒アニメーション)
	change_motion(actor, PlayerMotionID::POWER_UP);
}

// 更新処理
void PlayerState_Awake::update(Actor & actor, float deltaTime) {
	// 重力を加算
	mPosition += Vector3::Down * GRAVITY;

	// アニメーション終了時、待機状態(覚醒)に移行
	if (actor.getAnim().isAnimEnd()){
		change(PlayerState_Enum::A_IDLE);
	}
}

// 衝突判定
void PlayerState_Awake::collide(const Actor & other){}

// 終了時の処理
void PlayerState_Awake::end(){}
